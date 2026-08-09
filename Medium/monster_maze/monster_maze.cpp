#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using ll=long long;
using namespace std;
ll n,m,k;
vector<vector<bool>> is_bomb;
vector<pair<ll,ll>> steps;
vector<pair<ll,ll>> pork;
queue<ll> temp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	is_bomb.assign(n,vector<bool> (m,false));
	steps.resize(k);
	pork.resize(k);
	for (ll i=0;i<k;i++)
	{
		ll r,c,s,t; cin>>r>>c>>s>>t;
		pork[i]={r,c};
		steps[i]={s,t};
		temp.push(i);
	}
	vector<pair<ll,ll>> dies;
	while (!temp.empty())
	{
		ll sz=(ll)temp.size();
		for (ll i=0;i<sz;i++)
		{
			ll pos=temp.front();
			temp.pop();
			auto &[r,c]=pork[pos];
			is_bomb[r][c]=true;
			auto &[s,t]=steps[pos];
			r+=s; c+=t;
		}
		for (ll i=0;i<k;i++)
		{
			auto &[r,c]=pork[i];
			if (r==1000LL) continue;
			if (r<0 || c<0 || r>=n || c>=m)
			{r=1000LL;continue;}
			if (!is_bomb[r][c])
				temp.push(i);
			else
				dies.push_back({r,c});
		}
		for (auto &[r,c]:dies)
			is_bomb[r][c]=false;
		dies.clear();
	}
	ll total=0;
	for (ll i=0;i<n;i++)
		for (ll j=0;j<m;j++)
			if (is_bomb[i][j])
				total++;
	cout<<total;
	return 0;
}