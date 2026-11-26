#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
const ll INF=1000000007LL;
ll MOD(ll x) {return (x+INF)%INF;}
vector<vector<ll>> ship;
vector<ll> color;
vector<vector<ll>> dp;
void dfs(ll pwd)
{
    if (color[pwd]) dp[pwd][0LL]=1LL;
    else dp[pwd][1LL]=1LL;
    for (ll nxt:ship[pwd])
    {
        dfs(nxt);
        ll a=MOD(dp[pwd][0LL]),b=MOD(dp[pwd][1LL]);
        ll c=MOD(dp[nxt][0LL]),d=MOD(dp[nxt][1LL]);
        dp[pwd][0LL]=MOD(MOD(a*c)+MOD(a*d));
        dp[pwd][1LL]=MOD(MOD(MOD(b*c)+MOD(b*d))+MOD(a*d));
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    ship.resize(n,{});
    color.resize(n,0LL);
    for (ll i=1LL;i<n;i++)
    {
        ll x; cin>>x;
        ship[x].push_back(i);
    }
    for (ll i=0LL;i<n;i++) cin>>color[i];
    dp.resize(n,vector<ll> (2LL,0LL)); dfs(0LL);
    cout<<dp[0LL][1LL]<<'\n';
    return 0;
}
