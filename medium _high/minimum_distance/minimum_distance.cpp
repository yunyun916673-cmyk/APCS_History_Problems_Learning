#include <iostream>
#include <vector>
#include <queue>
using ll=long long;
using namespace std;
ll mod(ll x) {return x%1000000007;}
ll n,m;
vector<vector<ll>> ship;
vector<ll> dp;
vector<ll> dist;
void bfs()
{
    queue<ll> temp;
    temp.push(0LL);
    dist[0]=0;
    ll level=0;
    while (!temp.empty())
    {
        ll sz=(ll)temp.size();
        for (ll i=0;i<sz;i++)
        {
            ll pwd=temp.front(); temp.pop();
            for (ll nxt:ship[pwd])
            {
                if (level+1LL<=dist[nxt])
                {
                    dp[nxt]=mod(dp[nxt]+dp[pwd]);
                    if (level+1!=dist[nxt])
                    {
                        dist[nxt]=level+1LL;
                        temp.push(nxt);
                    }
                }
            }
        }
        level++;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    ship.resize(n);
    for (ll i=0;i<m;i++)
    {
        ll a,b; cin>>a>>b; a--; b--;
        ship[a].push_back(b);
        ship[b].push_back(a);
    }
    dp.assign(n,0LL); dp[0LL]=1LL;
    dist.assign(n,500000);
    bfs();
    cout<<dp[n-1LL];
    return 0;
}