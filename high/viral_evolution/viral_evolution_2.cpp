#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using ll=long long;
using namespace std;
const ll INF=4e18;
ll n,m;
ll root;
vector<vector<ll>> ship;
vector<string> rna;
vector<vector<vector<ll>>> dp;
//dp[pwd][j][t]=min(dp[pwd][j][t]+dp[chd][j][i=0123]+(t!=i))
ll get_type(char ch)
{
    if (ch=='A') return 0LL;
    else if (ch=='U') return 1LL;
    else if (ch=='C') return 2LL;
    else if (ch=='G') return 3LL;
    else return -1LL;
}
void dfs(ll pwd,ll pos)
{
    for (ll chd:ship[pwd]) dfs(chd,pos);
    if (rna[pwd][pos]=='@')
        for (ll i=0;i<4;i++) dp[pwd][pos][i]=0LL;
    else dp[pwd][pos][get_type(rna[pwd][pos])]=0LL;
    for (ll chd:ship[pwd])
    {
        for (ll p=0;p<4;p++)
        {
            ll cnt=INF;
            for (ll c=0;c<4;c++)
            {
                cnt=min(cnt,dp[pwd][pos][p]+dp[chd][pos][c]+(p!=c));
            }
            dp[pwd][pos][p]=cnt;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    ship.resize(n);
    rna.resize(n);
    for (ll i=0;i<n;i++)
    {
        ll u,v; cin>>u>>v; u--; v--;
        if (u==v) root=u;
        else ship[v].push_back(u);
        string s; cin>>s; rna[u]=s;
    }
    dp.assign(n,vector<vector<ll>> (m,vector<ll> (4,INF)));
    for (ll i=0;i<m;i++) dfs(root,i);
    ll ans=0LL;
    for (ll i=0;i<m;i++)
    {
        ll cnt=INF;
        for (ll j=0;j<4;j++)
        {
            cnt=min(dp[root][i][j],cnt);
        }
        ans+=cnt;
    }
    cout<<ans;
    return 0;
}
