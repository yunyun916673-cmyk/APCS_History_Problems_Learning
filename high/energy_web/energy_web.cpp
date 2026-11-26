#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll n;
vector<vector<ll>> ship;
vector<ll> A;
vector<vector<ll>> dp;
ll dfs(const ll& pwd,const ll& pnt)
{
    dp[pwd][0LL]=0LL;
    dp[pwd][1LL]=A[pwd];
    for (const ll& nxt:ship[pwd])
    {
        if (nxt==pnt) continue;
        dfs(nxt,pwd);
        dp[pwd][0LL]+=dp[nxt][1LL];
        dp[pwd][1LL]+=min(dp[nxt][0LL],dp[nxt][1LL]);
    }
    return min(dp[pwd][0LL],dp[pwd][1LL]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n; ship.resize(n);
    for (ll i=1LL;i<n;i++)
    {
        ll u,v; cin>>u>>v;
        ship[u].push_back(v);
        ship[v].push_back(u);
    }
    A.resize(n);
    for (ll i=0LL;i<n;i++) cin>>A[i];
    dp.resize(n,vector<ll> (2LL,0LL));
    cout<<dfs(0LL,-1LL)<<'\n'; return 0;
}
