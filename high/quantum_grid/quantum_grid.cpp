#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
const ll dr[4]={1LL,0LL,-1LL,0LL};
const ll dc[4]={0LL,1LL,0LL,-1LL};
ll n,m;
vector<vector<ll>> grid;
vector<vector<ll>> ship;
vector<ll> cells;
bool vers(const ll& a,const ll& b)
{return grid[a/n][a%n]<grid[b/n][b%n];}
vector<ll> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T; cin>>T;
    for (ll t=0LL;t<T;t++)
    {
        cin>>n>>m;
        grid.assign(n,vector<ll> (n));
        for(ll i=0LL;i<n;i++)for(ll j=0LL;j<n;j++)cin>>grid[i][j];
        ship.assign(n*n,vector<ll>());
        for (ll i=0LL;i<n;i++)
        {
            for (ll j=0LL;j<n;j++)
            {
                for (ll k=0LL;k<4LL;k++)
                {
                    ll ni=i+dr[k],nj=j+dc[k];
                    if (ni<0LL||nj<0LL||ni>=n||nj>=n) continue;
                    if (grid[ni][nj]<grid[i][j])
                        ship[i*n+j].push_back(ni*n+nj);
                }
            }
        }
        cells.assign(n*n,-1LL);
        for (ll i=0LL;i<n*n;i++) cells[i]=i;
        sort(cells.begin(),cells.end(),vers);
        dp.assign(n*n,-1LL); ll used=0LL;
        for(ll i=0LL;i<n*n;i++)if(ship[i].empty()){used++;dp[i]=0LL;}
        if (used>m) {cout<<"Impossible"<<'\n';continue;}
        for (const ll& u:cells)
        {
            if (dp[u]!=-1LL) continue; dp[u]=n*n;
            for (ll& v:ship[u]) dp[u]=min(dp[u],dp[v]+1LL);
        }
        ll ans=0LL; for (ll i=0LL;i<n*n;i++) ans=max(ans,dp[i]);
        cout<<ans<<'\n';
    }
    return 0;
}
