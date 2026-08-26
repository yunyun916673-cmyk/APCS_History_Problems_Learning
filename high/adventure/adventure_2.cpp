#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m,n;
vector<vector<int>> grid;
vector<vector<vector<int>>> memo;
void get_memo()
{
	for (int step=1;step<m+n-2;step++)
	{
		for (int i=0;i<m;i++)
		{
			for (int j=i+1;j<m;j++)
			{
				int c1=step-i,c2=step-j;
				if (c1<0||c2<0||c1>=n||c2>=n) continue;
				int cnt=-1;
				if (memo[step-1][i][j]!=-1) cnt=max(cnt,memo[step-1][i][j]);
				if (i>0&&memo[step-1][i-1][j]!=-1) cnt=max(cnt,memo[step-1][i-1][j]);
				if (memo[step-1][i][j-1]!=-1) cnt=max(cnt,memo[step-1][i][j-1]);
				if (i>0&&memo[step-1][i-1][j-1]!=-1) cnt=max(cnt,memo[step-1][i-1][j-1]);
				if (cnt!=-1) memo[step][i][j]=cnt+grid[i][c1]+grid[j][c2];
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cin>>m>>n;
	int tr=m-1,tc=n-1;
	grid.resize(m,vector<int> (n));
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			cin>>grid[i][j];
	memo.assign(m+n,vector<vector<int>> (m,vector<int> (m,-1))); memo[0][0][0]=0;
	get_memo();
	cout<<memo[m+n-3][m-2][m-1];
	return 0;
}