#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
using pll=pair<ll,ll>;
const ll dr[4]={0,1,0,-1};
const ll dc[4]={1,0,-1,0};
ll n,m;
vector<vector<vector<bool>>> grid;
vector<vector<bool>> visited;
ll ans=0;
ll total=0;
void dfs(ll r,ll c)
{
    visited[r][c]=true;
    total++;
    for (ll i=0;i<4;i++)
    {
        if (!grid[r][c][i]) continue;
        ll nr=r+dr[i];
        ll nc=c+dc[i];
        if (nr<0 || nc<0 || nr>=n || nc>=m)
            continue;
        if (visited[nr][nc]) continue;
        if (grid[nr][nc][(i+2LL)%4]) dfs(nr,nc);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    grid.assign(n,vector<vector<bool>> (m,vector<bool> (4,false)));
    visited.assign(n,vector<bool> (m,false));
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            char t; cin>>t;
            if (t=='F')
            {
                grid[i][j][0]=true;
                grid[i][j][1]=true;
            }
            else if (t=='H')
            {
                grid[i][j][0]=true;
                grid[i][j][2]=true;
            }
            else if (t=='7')
            {
                grid[i][j][1]=true;
                grid[i][j][2]=true;
            }
            else if (t=='I')
            {
                grid[i][j][1]=true;
                grid[i][j][3]=true;
            }
            else if (t=='X')
            {
                grid[i][j][0]=true;
                grid[i][j][1]=true;
                grid[i][j][2]=true;
                grid[i][j][3]=true;
            }
            else if (t=='L')
            {
                grid[i][j][0]=true;
                grid[i][j][3]=true;
            }
            else if (t=='J')
            {
                grid[i][j][2]=true;
                grid[i][j][3]=true;
            }
            else visited[i][j]=true;
            
        }
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            if (!visited[i][j])
            {
                total=0;
                dfs(i,j);
                ans=max(ans,total);
            }
        }
    }
    cout<<ans;
    return 0;
}
