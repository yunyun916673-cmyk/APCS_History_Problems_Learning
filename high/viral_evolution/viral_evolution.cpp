#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using ll=long long;
using namespace std;
const ll INF=1e18;
ll n,m;
vector<vector<ll>> tree;
vector<string> rna;
vector<vector<ll>> dp;
ll root;
ll get_type(char ch)
{
if (ch=='A') return 0;
else if (ch=='U') return 1;
else if (ch=='C') return 2;
else if (ch=='G') return 3;
else return -1;
}
void dfs(ll pwd,ll pos)
{
for (ll chd:tree[pwd]) dfs(chd,pos);
for (ll i=0;i<4;i++) dp[pwd][i]=INF;
ll x=get_type(rna[pwd][pos]);
if (x>=0) dp[pwd][x]=0;
else for (ll i=0;i<4;i++) dp[pwd][i]=0;
for (ll chd:tree[pwd])
{
vector<ll> tmp(4,INF);
for (ll i=0;i<4;i++)
{
for (ll j=0;j<4;j++)
{
ll y=(i==j?0:1);
tmp[i]=min(tmp[i],dp[pwd][i]+dp[chd][j]+y);
}
}
dp[pwd]=tmp;
}
return;
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
cin>>n>>m;
tree.resize(n);
rna.resize(n);
for (ll i=0;i<n;i++)
{
ll a,b; string s;
cin>>a>>b>>s; a--; b--;
rna[a]=s;
if (a==b) root=a;
else tree[b].push_back(a);
}
ll ans=0;
for (ll i=0;i<m;i++)
{
dp.assign(n,vector<ll> (4,INF));
dfs(root,i);
ll x=INF;
for (ll k=0;k<4;k++) x=min(x,dp[root][k]);
ans+=x;
}
cout<<ans;
return 0;
}