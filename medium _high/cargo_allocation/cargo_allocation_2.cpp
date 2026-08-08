#include <iostream>
#include <vector>
#include <utility>
using ll=long long;
using namespace std;
ll n,m;
vector<ll> Wt;
vector<pair<ll,ll>> ship;
vector<ll> goods;
void dfs(ll pwd)
{
    ll a=ship[pwd].first,b=ship[pwd].second;
    if (a!=0) {dfs(a); dfs(b);}
    if (pwd<n && pwd>1)
        Wt[pwd]+=Wt[a]+Wt[b];
    return;
}
ll pos,good;
void put_good(ll pwd)
{
    pos=pwd;
    ll a=ship[pwd].first,b=ship[pwd].second;
    if (pwd<n)
    {
        ll nxt=(Wt[a]>Wt[b]?b:a);
        put_good(nxt);
    }
    if (pwd!=1) Wt[pwd]+=good;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    Wt.assign(2*n+1,0LL);
    ship.assign(2*n+1,{0,0});
    goods.resize(m+1);
    for (ll i=n;i<2*n;i++) cin>>Wt[i];
    for (ll i=1;i<=m;i++) cin>>goods[i];
    for (ll i=0;i<n-1;i++)
    {
        ll a,b,c; cin>>a>>b>>c;
        ship[a]={b,c};
    }
    dfs(1);
    for (ll i=1;i<=m;i++)
    {
        good=goods[i];
        pos=1;
        put_good(1);
        cout<<pos;
        if (i!=m) cout<<" ";
    }
    return 0;
}
