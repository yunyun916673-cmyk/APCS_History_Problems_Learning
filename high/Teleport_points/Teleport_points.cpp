#include <iostream>
#include <vector>
#include <queue>
using ll=long long;
using namespace std;
ll n,p,l,r;
vector<ll> grid;
ll level=0;
bool bfs()
{
	vector<bool> visited(n,false);
	queue<ll> temp;
	temp.push(0);
	while (!temp.empty())
	{
		ll sz=(ll)temp.size();
		for (ll i=0;i<sz;i++)
		{
			ll cur=temp.front();
			temp.pop();
			visited[cur]=true;
			cur=grid[cur];
			if (cur==p)
				return true;
			ll nxt=cur-l;
			if (nxt>=0 && !visited[nxt])
				temp.push(nxt);
			nxt+=(l+r);
			if (nxt<n && !visited[nxt])
				temp.push(nxt);
		}
		level++;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>p>>l>>r;
	grid.resize(n);
	for (ll i=0;i<n;i++)
		cin>>grid[i];
	if (bfs())
		cout<<level;
	else
		cout<<-1;
	return 0;
}