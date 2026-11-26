#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
struct dat {ll W,V,C;};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<dat> line(n+1LL);
    for (ll i=1LL;i<=n;i++) cin>>line[i].W>>line[i].V>>line[i].C;
    ll t; cin>>t;
    vector<vector<ll>> dp(n+1LL,vector<ll> (t+1LL,0LL));
    for (ll i=1LL;i<=n;i++)
    {
        for (ll j=1LL;j<=t;j++)
        {
            dp[i][j]=dp[i-1LL][j];
            for (ll k=1LL;k<=line[i].C&&j-k*line[i].W>=0LL;k++)
            {
                dp[i][j]=max(dp[i][j],dp[i-1LL][j-k*line[i].W]+k*line[i].V);
            }
        }
    }
    cout<<dp[n][t]<<'\n'; return 0;
}
