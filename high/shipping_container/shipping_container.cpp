#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; cin>>n>>k; vector<int> line(n+1,0);
    int total=0;
    for (int i=1;i<=n;i++) {cin>>line[i];total+=line[i];}
    bitset<100005> dp; dp[0]=1;
    for (int i=1;i<=n;i++) dp|=(dp<<line[i]);
    int cnt1=0,cnt2=total;
    for (int i=total/2;i>0;i--)
    {
        if (!dp[i]) continue;
        if (abs(i-(total-i))<abs(cnt1-cnt2))
        {
            cnt1=i; cnt2=total-i;
            break;
        }
    }
    cout<<min(cnt1,cnt2)<<' '<<max(cnt1,cnt2)<<'\n'; return 0;
}
