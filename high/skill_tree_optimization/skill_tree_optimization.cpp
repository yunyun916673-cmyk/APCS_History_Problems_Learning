#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using ll=long long;
using namespace std;
ll n,m; vector<ll> A;
vector<vector<ll>> ship;
vector<vector<ll>> dp;
void dfs(const ll& pwd,const ll& pnt)
{
    dp[pwd][0LL]=0LL;
    dp[pwd][1LL]=A[pwd];
    for (const ll& nxt:ship[pwd])
    {
        if (nxt==pnt) continue; dfs(nxt,pwd);
        for (ll j=m;j>=0LL;j--) for (ll k=0LL;k<j;k++)
        dp[pwd][j]=max(dp[pwd][j],dp[pwd][j-k]+dp[nxt][k]);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>n>>m;
    ship.resize(n); A.resize(n);
    dp.resize(n,vector<ll> (m+1LL,LLONG_MIN/4LL));
    for (ll i=1LL;i<n;i++)
    {
        ll u,v; cin>>u>>v;
        ship[u].push_back(v);
        ship[v].push_back(u);
    }
    for (ll i=0LL;i<n;i++) cin>>A[i];
    dfs(0LL,-1LL);
    cout<<dp[0LL][m]<<'\n';
    return 0;
}
