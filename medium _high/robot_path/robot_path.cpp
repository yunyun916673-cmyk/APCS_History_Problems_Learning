#include <iostream>
#include <vector>
using namespace std;
const int dr[4]={0,-1,0,1};
const int dc[4]={-1,0,1,0};
int n,m;
int sr=0,sc=0;
vector<vector<int>> grid;
long long total=0;
vector<vector<bool>> visited;
void walk(int r,int c)
{
    total+=(long long)grid[r][c];
    visited[r][c]=true;
    int nr=-1,nc=-1;
    int tr,tc;
    for (int i=0;i<4;i++)
    {
        tr=r+dr[i]; tc=c+dc[i];
        if (tr<0 || tc<0 || tr>=n || tc>=m || visited[tr][tc])
            continue;
        if (nr==-1 || grid[tr][tc]<grid[nr][nc])
        {nr=tr;nc=tc;}
    }
    if (nr==-1) return;
    walk(nr,nc);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    grid.resize(n,vector<int> (m));
    visited.resize(n,vector<bool> (m,false));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if (grid[sr][sc]>grid[i][j])
            {sr=i; sc=j;}
        }
    walk(sr,sc);
    cout<<total;
    return 0;
}
