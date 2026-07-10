#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<tuple<int,int,int>> ch(n);
    for (int i=0;i<n;i++)
    {
        int a,d; cin>>a>>d;
        int ab=a*a+d*d;
        ch[i]={ab,a,d};
    }
    sort(ch.begin(),ch.end());
    cout<<get<1>(ch[n-2])<<" "<<get<2>(ch[n-2]);
    return 0;
}
