#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll n;
vector<vector<ll>> ship;
vector<ll> A;
vector<vector<ll>> dp;
ll dfs(ll pwd,ll pnt)
{
    dp[pwd][0LL]=0LL;
    dp[pwd][1LL]=A[pwd];
    for (const ll& nxt:ship[pwd])
    {
        if (nxt!=pnt)
        {
            dfs(nxt,pwd);
            dp[pwd][0LL]+=max(dp[nxt][1LL],dp[nxt][0LL]);
            dp[pwd][1LL]+=dp[nxt][0LL];
        }
    }
    return max(dp[pwd][1LL],dp[pwd][0LL]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin>>n;
    ship.resize(n);
    for (ll i=1LL;i<n;i++)
    {
        ll u,v; cin>>u>>v;
        ship[u].push_back(v);
        ship[v].push_back(u);
    }
    A.resize(n);
    for (ll i=0LL;i<n;i++) cin>>A[i];
    dp.resize(n,vector<ll> (2LL,0LL));
    cout<<dfs(0LL,-1LL)<<'\n';
    return 0;
}
