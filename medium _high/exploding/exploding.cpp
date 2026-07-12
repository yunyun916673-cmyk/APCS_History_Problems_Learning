#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using ll=long long;
using namespace std;
ll m,n,q;
ll sr,sc;
vector<vector<ll>> grid;
const ll dr[4]={-1,0,1,0};
const ll dc[4]={0,-1,0,1};
bool bfs(ll org)
{
	vector<vector<bool>> visited(m,vector<bool> (n,false));
	queue<pair<ll,ll>> temp;
	visited[sr][sc]=true;
	temp.push({sr,sc});
	ll bombed=1;
	while (!temp.empty())
	{
		auto [r,c]=temp.front();
		temp.pop();
		ll rad=(grid[r][c]>0?grid[r][c]:(grid[r][c]==-2?org:0));
		vector<vector<ll>> dist(m,vector<ll> (n,-1));
		queue<pair<ll,ll>> spread;
		dist[r][c]=0;
		spread.push({r,c});
		while (!spread.empty())
		{
			auto [x,y]=spread.front();
			spread.pop();
			for (ll i=0;i<4LL;i++)
			{
				ll nx=x+dr[i];
				ll ny=y+dc[i];
				if (nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]==-1 || dist[nx][ny]!=-1) continue;
				ll thedist=dist[x][y]+1LL;
				if (thedist>rad) continue;
				dist[nx][ny]=thedist;
				if (!visited[nx][ny])
				{
					visited[nx][ny]=true;
					bombed++;
					if (grid[nx][ny]>0)
						temp.push({nx,ny});
				}
				spread.push({nx,ny});
			}
		}
	}
	return bombed>=q;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>m>>n>>q;
	grid.assign(m,vector<ll> (n));
	for (ll i=0;i<m;i++)
		for (ll j=0;j<n;j++)
		{
			cin>>grid[i][j];
			if (grid[i][j]==-2)
			{ sr=i; sc=j; }
		}
	ll left=1,right=m+n-2,ans=right;
	while (left<=right)
	{
		ll mid=(left+right)/2;
		if (bfs(mid)) 
		{ right=mid-1LL; ans=mid; }
		else left=mid+1LL;
	}
	cout<<ans;
	return 0;
}