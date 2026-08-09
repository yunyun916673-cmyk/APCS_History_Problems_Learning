#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using ll=long long;
using namespace std;
ll n;
vector<int> colors;
vector<vector<pair<ll,ll>>> ship;
void bfs()
{
    queue<ll> temp;
    vector<ll> visited(n,false);
    temp.push(0LL);
    visited[0LL]=true;
    while (!temp.empty())
    {
        ll pwd=temp.front(); temp.pop();
        for (auto [chd,val]:ship[pwd])
        {
            if (!visited[chd])
            {
                visited[chd]=true;
                temp.push(chd);
                ll color=colors[pwd];
                if (val) colors[chd]=!color;
                else colors[chd]=color;
            }
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    colors.assign(n,0);
    ship.resize(n);
    for (ll i=0;i<n-1LL;i++)
    {
        ll u,v,w; cin>>u>>v>>w;
        u--; v--; w%=2;
        ship[u].push_back({v,w});
        ship[v].push_back({u,w});
    }
    bfs();
    for (ll i=0;i<n;i++)
    {
        cout<<colors[i];
        if (i!=n-1LL) cout<<"\n";
    }
    return 0;
}