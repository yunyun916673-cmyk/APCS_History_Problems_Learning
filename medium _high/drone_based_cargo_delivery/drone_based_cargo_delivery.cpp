#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
using namespace std;
vector<vector<int>> grid;
string bfs(const int& sr,const int& sc,const int& tr,const int& tc)
{
    queue<pair<int,int>> temp; temp.push({sr,sc});
    int ans=-1; int level=0;
    grid[sr][sc]=1;
    while (!temp.empty())
    {
        int sz=(int)temp.size();
        for (int s=0;s<sz;s++)
        {
            auto [r,c]=temp.front(); temp.pop();
            int dr,dc,nr,nc;
            dr=r-1;dc=c; 
            if (dr>=0&&dc>=0&&dr<100&&dc<100&&grid[dr][dc]!=2)
            {
                nr=r-3;nc=c-1;
                if (nr>=0&&nc>=0&&nr<100&&nc<100&&grid[nr][nc]==0)
                {
                    grid[nr][nc]=1;
                    if (nr==tr&&nc==tc) return to_string(level+1);
                    temp.push({nr,nc});
                }
                nc=c+1;
                if (nr>=0&&nc>=0&&nr<100&&nc<100&&grid[nr][nc]==0)
                {
                    grid[nr][nc]=1;
                    if (nr==tr&&nc==tc) return to_string(level+1);
                    temp.push({nr,nc});
                }
            }
            dr=r;dc=c+1;
            if (dr>=0&&dc>=0&&dr<100&&dc<100&&grid[dr][dc]!=2)
            {
                nr=r-1;nc=c+3;
                if (nr>=0&&nc>=0&&nr<100&&nc<100&&grid[nr][nc]==0)
                {
                    grid[nr][nc]=1;
                    if (nr==tr&&nc==tc) return to_string(level+1);
                    temp.push({nr,nc});
                }
                nr=r+1;
                if (nr>=0&&nc>=0&&nr<100&&nc<100&&grid[nr][nc]==0)
                {
                    grid[nr][nc]=1;
                    if (nr==tr&&nc==tc) return to_string(level+1);
                    temp.push({nr,nc});
                }
            }
            dr=r+1;dc=c;
            if (dr>=0&&dc>=0&&dr<100&&dc<100&&grid[dr][dc]!=2)
            {
                nr=r+3;nc=c+1;
                if (nr>=0&&nc>=0&&nr<100&&nc<100&&grid[nr][nc]==0)
                {
                    grid[nr][nc]=1;
                    if (nr==tr&&nc==tc) return to_string(level+1);
                    temp.push({nr,nc});
                }
                nc=c-1;
                if (nr>=0&&nc>=0&&nr<100&&nc<100&&grid[nr][nc]==0)
                {
                    grid[nr][nc]=1;
                    if (nr==tr&&nc==tc) return to_string(level+1);
                    temp.push({nr,nc});
                }
            }
            dr=r;dc=c-1;
            if (dr>=0&&dc>=0&&dr<100&&dc<100&&grid[dr][dc]!=2)
            {
                nr=r-1;nc=c-3;
                if (nr>=0&&nc>=0&&nr<100&&nc<100&&grid[nr][nc]==0)
                {
                    grid[nr][nc]=1;
                    if (nr==tr&&nc==tc) return to_string(level+1);
                    temp.push({nr,nc});
                }
                nr=r+1;
                if (nr>=0&&nc>=0&&nr<100&&nc<100&&grid[nr][nc]==0)
                {
                    grid[nr][nc]=1;
                    if (nr==tr&&nc==tc) return to_string(level+1);
                    temp.push({nr,nc});
                }
            }
        }
        level++;
    }
    return "impossible";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);int n;
    while (cin>>n)
    {
        grid.assign(100,vector<int> (100,0));
        for (int i=0;i<n;i++)
        {
            int r,c; cin>>r>>c;
            grid[r][c]=2;
        }
        int sr,sc; cin>>sr>>sc;
        int tr,tc; cin>>tr>>tc;
        cout<<bfs(sr,sc,tr,tc)<<"\n";
    }
    return 0;
}
