#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n,p,q,tx,ty,level=0;
    cin>>m>>n>>p>>q>>tx>>ty;
    if (tx==0 && ty==0) {cout<<0; return 0;}
    queue<tuple<int,int,int>> temp;
    vector<vector<int>> grid(m,vector<int> (n,0));
    for (int i=0;i<p;i++)
    {int x,y; cin>>x>>y; grid[x][y]=-1;}
    for (int i=0;i<q;i++)
    {int x,y; cin>>x>>y; grid[x][y]=1;}
    vector<vector<vector<bool>>> visited(m,vector<vector<bool>> (n,vector<bool> (4,false)));
    for (int i=0;i<4;i++) {temp.push({0,0,i});visited[0][0][i]=true;}
    while (!temp.empty())
    {
        int sz=(int)temp.size();
        for (int i=0;i<sz;i++)
        {
            auto [x,y,d]=temp.front(); temp.pop();
            auto &noww=grid[x][y];
            for (int i=0;i<4;i++)
            {
                if (noww==1 && i==(d+3)%4) continue;
                int nx=x+dx[i],ny=y+dy[i];
                if (nx<0 || ny<0 || nx>=m || ny>=n) continue;
                if (grid[nx][ny]<0) continue;
                if (visited[nx][ny][i]) continue;
                if (nx==tx && ny==ty) {cout<<level+1; return 0;}
                visited[nx][ny][i]=true;
                temp.push({nx,ny,i});
            }
        } level++;
    } return 0;
}