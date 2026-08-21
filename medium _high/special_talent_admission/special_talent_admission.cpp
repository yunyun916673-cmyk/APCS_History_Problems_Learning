#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    unordered_map<int,vector<int>> ship;
    unordered_map<int,int> visited;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<m;j++)
        {
            int x; cin>>x;
            int a=i*m+j,b=i*m+j+1;
            if (x)
            {
                ship[a].push_back(b);
                ship[b].push_back(a);
                visited[a]=1;
                visited[b]=1;
            }
            else
            {
                if (!visited.count(a)) visited[a]=2;
                if (!visited.count(b)) visited[b]=2;
            }
        }
    }
    for (int i=1;i<n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            int x; cin>>x;
            int a=i*m+j,b=(i+1)*m+j;
            if (x)
            {
                ship[a].push_back(b);
                ship[b].push_back(a);
                visited[a]=1;
                visited[b]=1;
            }
            else
            {
                if (!visited.count(a)) visited[a]=2;
                if (!visited.count(b)) visited[b]=2;
            }
        }
    }
    int ans=0; int cnt=0LL;
    queue<pair<int,int>> temp;
    for (auto &[node,tag]:visited)
    {
        if (tag==0) continue;
        if (tag==1)
        {
            temp.push({node,-1});
            visited[node]=0;
            while (!temp.empty())
            {
                auto [pwd,pnt]=temp.front();
                temp.pop();
                for (int nxt:ship[pwd])
                {
                    if (nxt==pnt) continue;
                    if (visited[nxt]==0)
                    {ans++;continue;}
                    temp.push({nxt,pwd});
                    visited[nxt]=0;
                }
            }
        }
        cnt++;
    }
    cout<<ans/2+cnt-1; return 0;
}
