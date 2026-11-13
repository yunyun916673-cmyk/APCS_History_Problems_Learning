#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
#include <climits>
#include <array>
using namespace std;
const int INF=INT_MAX/2;
const int dr[4]={1,0,-1,0};
const int dc[4]={0,1,0,-1};
int R,C,D; vector<vector<char>> grid;
vector<vector<int>> BFS1(const int& sr,const int& sc)
{
    queue<pair<int,int>> temp; temp.push(make_pair(sr,sc));
    vector<vector<int>> dist(R+1,vector<int> (C+1,INF));
    dist[sr][sc]=0; int level=0;
    while (!temp.empty())
    {
        int sz=(int)temp.size();
        while (sz--)
        {
            auto [r,c]=temp.front(); temp.pop();
            for (int i=0;i<4;i++)
            {
                int nr=r+dr[i],nc=c+dc[i];
                if (nr<=0||nc<=0||nr>R||nc>C) continue;
                if (grid[nr][nc]=='X') continue;
                if (dist[nr][nc]!=INF) continue;
                dist[nr][nc]=level+1;
                temp.push(make_pair(nr,nc));
            }
        }
        level++;
    }
    return dist;
}
vector<vector<array<int,2>>> BFS2(const int& sr,const int& sc)
{
    queue<tuple<int,int,int>> temp; temp.push(make_tuple(sr,sc,false));
    vector<vector<array<int,2>>> dist(R+1,vector<array<int,2>> (C+1,{INF,INF}));
    dist[sr][sc][0]=0; int level=0;
    while (level<D&&!temp.empty())
    {
        int sz=(int)temp.size();
        while (sz--)
        {
            if (level>=D) break;
            auto [r,c,tag]=temp.front(); temp.pop();
            for (int i=0;i<4;i++)
            {
                int nr=r+dr[i],nc=c+dc[i];
                if (nr<=0||nc<=0||nr>R||nc>C) continue;
                bool new_tag=tag;
                if (grid[nr][nc]=='X')
                {
                    if (new_tag) continue;
                    else new_tag=!tag;
                }
                if (dist[nr][nc][new_tag]!=INF) continue;
                dist[nr][nc][new_tag]=level+1;
                temp.push(make_tuple(nr,nc,new_tag));
            }
        }
        level++;
    }
    return dist;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>R>>C>>D;
    int sr=-1,sc=-1,er=-1,ec=-1,br=-1,bc=-1;
    grid.resize(R+1,vector<char> (C+1,'X'));
    for (int i=1;i<=R;i++)
    {
        for (int j=1;j<=C;j++)
        {
            char ch; cin>>ch;
            if (ch=='.') grid[i][j]=ch;
            else if (ch=='X') grid[i][j]=ch;
            else if (ch=='B') {sr=i;sc=j;grid[i][j]=ch;}
            else if (ch=='E') {er=i;ec=j;grid[i][j]=ch;}
            else if (ch=='P') {br=i;bc=j;grid[i][j]=ch;}
        }
    }
    if (br==-1) {br=sr;bc=sc;grid[br][bc]='.';}
    auto distS=BFS1(sr,sc); auto distE=BFS1(er,ec);
    int length=distS[er][ec]; if (length==INF) {cout<<-1<<'\n'; return 0;}
    auto distP=BFS2(br,bc);
    int ans=INF;
    for (int i=1;i<=R;i++) for (int j=1;j<=C;j++)
    if (distS[i][j]+distE[i][j]==length&&!(distP[i][j][0]==INF&&distP[i][j][1]==INF))
    ans=min(ans,max(length,distS[i][j]+min(distP[i][j][0],distP[i][j][1])));
    cout<<(ans==INF?-1:ans)<<'\n'; return 0;
}
