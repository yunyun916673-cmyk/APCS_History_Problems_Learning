//最大匹配、最小點覆蓋、最大獨立集、Konig定理:最大匹配=最小點覆蓋
//最大獨立集=總頂點數-最小點覆蓋=總頂點數-最大匹配
#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll N1,N2,M;
vector<vector<ll>> ship;
vector<bool> visited;
vector<ll> match;
bool dfs(ll pwd)
{
    for (const ll& nxt:ship[pwd])
    {
        if (visited[nxt]) continue;
        visited[nxt]=true;
        if (match[nxt]==0LL||dfs(match[nxt])) {match[nxt]=pwd;return true;}
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N1>>N2>>M;
    ship.resize(N1+1LL,{});
    while (M--)
    {
        ll u,v; cin>>u>>v;
        ship[u].push_back(v);
    }
    match.resize(N2+1LL,0LL);
    ll ans=0LL;
    for (ll i=1LL;i<=N1;i++)
    {
        visited.assign(N2+1LL,false);
        if (dfs(i)) ans++;
    }
    cout<<N1+N2-ans<<'\n'; return 0;
}
