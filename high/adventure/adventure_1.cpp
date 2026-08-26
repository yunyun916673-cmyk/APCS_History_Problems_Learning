#include <iostream>
#include <vector>
using namespace std;
int m,n; vector<vector<int>> grid;
int sr=0,sc=0,tr,tc;
vector<vector<bool>> visited;
int ans=0,step=0;
void dfs(int r,int c,bool is_down);
void go_down(int r,int c)
{
	int nr,nc;
	nr=r; nc=c+1;
	if (nc<n&&!visited[nr][nc])
	{
		visited[nr][nc]=true;
		step+=grid[nr][nc];
		dfs(nr,nc,true);
		visited[nr][nc]=false;
		step-=grid[nr][nc];
	}
	nr=r+1; nc=c;
	if (nr<m&&!visited[nr][nc])
	{
		visited[nr][nc]=true;
		step+=grid[nr][nc];
		dfs(nr,nc,true);
		visited[nr][nc]=false;
		step-=grid[nr][nc];
	}
	return;
}
void go_up(int r,int c)
{
	int nr,nc;
	nr=r; nc=c-1;
	if (nc>=0&&!visited[nr][nc])
	{
		visited[nr][nc]=true;
		step+=grid[nr][nc];
		dfs(nr,nc,false);
		visited[nr][nc]=false;
		step-=grid[nr][nc];
	}
	nr=r-1; nc=c;
	if (nr>=0&&!visited[nr][nc])
	{
		visited[nr][nc]=true;
		step+=grid[nr][nc];
		dfs(nr,nc,false);
		visited[nr][nc]=false;
		step-=grid[nr][nc];
	}
	return;
}
void dfs(int r,int c,bool is_down)
{
	if (is_down)
	{
		if (r==tr&&c==tc)
		{is_down=false;go_up(r,c);}
		else {go_down(r,c);}
		return;
	}
	if (r==sr&&c==sc)
	{ans=max(ans,step);}
	else {go_up(r,c);}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cin>>m>>n;
	tr=m-1; tc=n-1;
	grid.resize(m,vector<int> (n));
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			cin>>grid[i][j];
	visited.assign(m,vector<bool> (n,false));
	dfs(0,0,true); cout<<ans; return 0;
}