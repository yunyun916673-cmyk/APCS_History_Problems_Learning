#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using ll=long long;
using namespace std;
ll n;
vector<vector<ll>> ship;
vector<ll> C;
ll ans=-1LL*(LLONG_MAX/4LL);
ll dfs(const ll& pwd,const ll& pnt)
{
    ll cnt=C[pwd];
    for (const ll& nxt:ship[pwd])
    {
        if (nxt==pnt) continue;
        cnt+=max(0LL,dfs(nxt,pwd));
    }
    ans=max(ans,cnt);
    return cnt;
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
    C.resize(n);
    for (ll i=0LL;i<n;i++) cin>>C[i];
    dfs(0LL,-1LL); cout<<ans<<'\n';
    return 0;
}
