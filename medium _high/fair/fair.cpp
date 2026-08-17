#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,m,k,s;
vector<vector<ll>> popcorn;
vector<vector<ll>> ship;
vector<vector<ll>> dp;
queue<ll> temp;
void bfs(ll org)
{ ll level=0LL;
    for (ll corn:popcorn[org]) temp.push(corn);
    while (!temp.empty())
    {
        ll sz=(ll)temp.size();
        for (ll i=0LL;i<sz;i++)
        {
           ll pwd=temp.front(); temp.pop();
           for (ll nxt:ship[pwd])
           {
               auto &cnt=dp[org][nxt];
               if (level+1LL>=cnt) continue;
               cnt=level+1LL;temp.push(nxt);
           }
        }
        level++;
    } return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k>>s;
    popcorn.resize(k);
    ship.resize(n);
    dp.assign(k,vector<ll> (n,150000));
    for (ll i=0LL;i<n;i++)
    {
        ll p;cin>>p;dp[p-1LL][i]=0LL;
        popcorn[p-1LL].push_back(i);
    }
    for (ll i=0LL;i<m;i++)
    {
        ll u,v; cin>>u>>v; u--; v--;
        ship[u].push_back(v);
        ship[v].push_back(u);
    }
    for (ll i=0LL;i<k;i++) bfs(i);
    vector<ll> cursion;
    for (ll i=0LL;i<n;i++)
    { ll total=0LL;
        for (ll j=0LL;j<k;j++)
            cursion.push_back(dp[j][i]);
        sort(cursion.begin(),cursion.end());
        for (ll j=0LL;j<s;j++) total+=cursion[j];
        cout<<total; if (i!=n-1LL) cout<<" ";
        cursion.clear();
    } return 0;
}