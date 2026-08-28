#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> grid;
vector<vector<int>> dp;
int func(const vector<int>& line,const int& m)
{
	int ans=0;
	for (int i=1;i<=m;i++)
	{
		int len=500,lon=0;
		for (int j=i;j<=m;j++)
		{
			lon++;
			len=min(len,line[j]);
			ans=max(ans,lon*len);
		}
	}
	return ans;
}
int get_ans(const int& m,const int& n)
{
	dp.assign(n+1,vector<int> (m+1,0));
	for (int i=1;i<=m;i++)
	{
		dp[n][i]=grid[i][n];
		for (int j=n-1;j>0;j--)
			if (grid[i][j])
				dp[j][i]=dp[j+1][i]+1;
	}
	int ans=0;
	for (int j=1;j<=n;j++)
		ans=max(ans,func(dp[j],m));
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); int m,n;
	cin>>m>>n;
	grid.assign(m+1,vector<int> (n+1,0));
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			cin>>grid[i][j];
	cout<<get_ans(m,n); return 0;
}