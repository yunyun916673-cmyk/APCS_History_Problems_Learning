#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
ll n,m;
vector<vector<ll>> tree;
vector<ll> Wt;
vector<ll> goods;
void dfs(ll pwd,ll pnt)
{
    for (ll chd:tree[pwd])
        dfs(chd,pwd);
    if (pnt>0) Wt[pnt]+=Wt[pwd];
    return;
}
ll walk(ll q)
{
    ll nowx=1;
    while (nowx<=n-1LL)
    {
        if (nowx!=1) Wt[nowx]+=q;
        if (Wt[tree[nowx][0]]<=Wt[tree[nowx][1]])
            nowx=tree[nowx][0];
        else nowx=tree[nowx][1];
    }
    Wt[nowx]+=q;
    return nowx;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    tree.resize(2*n);
    Wt.assign(2*n,0);
    goods.resize(m+1LL);
    for (ll i=n;i<=2*n-1LL;i++)
        cin>>Wt[i];
    for (ll i=1;i<=m;i++)
        cin>>goods[i];
    for (ll i=1;i<=n-1LL;i++)
    {
        ll p,s,t; cin>>p>>s>>t;
        tree[p].push_back(s);
        tree[p].push_back(t);
    }
    dfs(1,0);
    for (ll i=1;i<=m;i++)
    {
        cout<<walk(goods[i]);
        if (i!=m) cout<<" ";
    }
    return 0;
}
