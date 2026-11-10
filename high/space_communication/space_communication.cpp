#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> ship;
int root1=-1;
int cur1=0;
void dfs1(int pwd,int pnt,int step)
{
    if (step>cur1) {root1=pwd;cur1=step;}
    for (int nxt:ship[pwd]) if (nxt!=pnt) dfs1(nxt,pwd,step+1);
    return;
}
int root2=root1;
int cur2=0;
void dfs2(int pwd,int pnt,int step)
{
    if (step>cur2) {root2=pwd;cur2=step;}
    for (int nxt:ship[pwd]) if (nxt!=pnt) dfs2(nxt,pwd,step+1);
    return;
}
vector<int> paths={};
bool dfs3(int pwd,int pnt,int step)
{
    bool tag=false;
    if (step==cur2) tag=true;
    for (int nxt:ship[pwd]) if (nxt!=pnt&&dfs3(nxt,pwd,step+1)) tag=true;
    if (tag) {paths.push_back(pwd);return true;} return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    ship.resize(n);
    for (int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        ship[u].push_back(v);
        ship[v].push_back(u);
    }
    dfs1(0,-1,0); dfs2(root1,-1,0); dfs3(root1,-1,0); dfs3(root2,-1,0);
    sort(paths.begin(),paths.end()); paths.erase(unique(paths.begin(),paths.end()),paths.end());
    for (const int& path:paths) cout<<path<<'\n';
    return 0;
}
