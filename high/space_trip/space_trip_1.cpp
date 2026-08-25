#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <algorithm>
using ll=long long;
using namespace std;
vector<ll> C;
vector<unordered_set<ll>> NOT;
vector<vector<pair<ll,ll>>> ship;
unordered_set<ll> cannot;
ll ans=1e18;
void dfs(ll pwd,ll step,ll endd)
{
	if (pwd==endd)
	{ans=min(ans,step);return;}
	vector<ll> temp;
	for (ll nt:NOT[C[pwd]])
	{
		if (!cannot.count(nt))
		{
			cannot.insert(nt);
			temp.push_back(nt);
		}
	}
	for (auto &[nxt,dist]:ship[pwd])
	{
		if (cannot.count(C[nxt]))
			continue;
		if (dist+step>=ans)
			continue;
		dfs(nxt,dist+step,endd);
	}
	for (ll cur:temp)
		cannot.erase(cur);
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
			if (x) NOT[j].insert(i);
		}
	}
	ship.resize(n+1LL);
	for (ll i=1LL;i<=m;i++)
	{
		ll u,v,d; cin>>u>>v>>d;
		ship[u].push_back({v,d});
		ship[v].push_back({u,d});
	}
	dfs(s,0LL,t);
	ans=(ans==1e18?-1LL:ans);
	cout<<ans; return 0;
}