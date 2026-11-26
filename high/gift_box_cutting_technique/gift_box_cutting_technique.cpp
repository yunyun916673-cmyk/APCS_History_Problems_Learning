#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll m,n,k;
vector<vector<ll>> dp;
vector<vector<ll>> best;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n>>k;
    dp.resize(m+5LL,vector<ll> (n+5LL,0LL));
    best.resize(m+5LL,vector<ll> (n+5LL,0LL));
    for (ll i=1LL;i<=k;i++)
    {
        ll h,w,p; cin>>h>>w>>p;
        if (h<=m&&w<=n) best[h][w]=max(best[h][w],p);
        if (w<=m&&h<=n) best[w][h]=max(best[w][h],p);
    }
    for (ll i=1LL;i<=m;i++) for (ll j=1LL;j<=n;j++)
    best[i][j]=max({best[i][j],best[i-1LL][j],best[i][j-1LL]});
    for (ll i=1LL;i<=m;i++) for (ll j=1LL;j<=n;j++)
    {
        dp[i][j]=best[i][j];
        for (ll s=1LL;s<=i/2LL;s++) dp[i][j]=max(dp[i][j],dp[s][j]+dp[i-s][j]);
        for (ll p=1LL;p<=j/2LL;p++) dp[i][j]=max({dp[i][j],dp[i][p]+dp[i][j-p]});
    }
    cout<<dp[m][n]<<'\n'; return 0;
}
