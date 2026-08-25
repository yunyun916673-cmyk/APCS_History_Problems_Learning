#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using ll=long long;
using namespace std;
vector<ll> C;
vector<vector<ll>> NOT;
vector<vector<pair<ll,ll>>> ship;
vector<ll> cannot;
ll ans=1e18;
void dfs(ll pwd,ll step,ll endd)
{
	if (pwd==endd)
	{ans=min(ans,step);return;}
	for (ll nt:NOT[C[pwd]])
		cannot[nt]++;
	for (auto &[nxt,dist]:ship[pwd])
	{
		if (cannot[C[nxt]]>0LL)
			continue;
		if (dist+step>=ans)
			continue;
		dfs(nxt,dist+step,endd);
	}
	for (ll nt:NOT[C[pwd]])
		cannot[nt]--;
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,k,m,s,t; cin>>n>>k>>m>>s>>t;
	 C.resize(n+1LL);
	for (ll i=1LL;i<=n;i++) cin>>C[i];
	NOT.resize(k+1LL);
	for (ll i=1LL;i<=k;i++)
	{
		for (ll j=1LL;j<=k;j++)
		{
			ll x; cin>>x;
			if (x) NOT[j].push_back(i);
		}
	}
	ship.resize(n+1LL);
	for (ll i=1LL;i<=m;i++)
	{
		ll u,v,d; cin>>u>>v>>d;
		ship[u].push_back({v,d});
		ship[v].push_back({u,d});
	}
	cannot.assign(k+1LL,0LL);
	dfs(s,0LL,t);
	ans=(ans==1e18?-1LL:ans);
	cout<<ans; return 0;
}