#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int> vec(n+1,0);
    for (int i=1;i<=n;i++) cin>>vec[i];
    sort(vec.begin()+1,vec.end());
    bitset<100005> line; line.set(); line[0]=0;
    bitset<100005> valid=line;
    bitset<100005> occuried_mask(0b11111);
    bitset<100005> invalidate_mask(0b111111111);
    for (int i=1;i<=n;i++)
    {
        int pos=valid._Find_next(vec[i]-1);
        line&=~(occuried_mask<<pos);
        if (pos>=4) valid&=~(invalidate_mask<<(pos-4));
        else valid&=~(invalidate_mask>>(4-pos));
    }
    line&=line>>1; line&=line>>2; line&=line>>4; line&=line>>8; line&=line>>14;
    cout<<line._Find_first()+30<<'\n'; return 0;
}
