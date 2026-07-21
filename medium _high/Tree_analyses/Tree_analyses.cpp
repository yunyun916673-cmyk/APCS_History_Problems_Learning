#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll n;
vector<vector<ll>> tree;
vector<bool> chldn;
ll root;
vector<ll> high;
void dfs(ll pwd)
{
    high[pwd]=0;
    for (ll chd:tree[pwd])
    {
        dfs(chd);
        high[pwd]=max(high[pwd],high[chd]+1LL);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    tree.resize(n);
    chldn.resize(n,false);
    high.resize(n);
    for (ll i=0;i<n;i++)
    {
        ll x; cin>>x;
        for (ll j=0;j<x;j++)
        {
            ll y; cin>>y; y--;
            tree[i].push_back(y);
            chldn[y]=true;
        }
    }
    for (ll i=0;i<n;i++)
    {
        if (!chldn[i]) {root=i;break;}
    }
    dfs(root);
    ll total=0;
    for (ll i=0;i<n;i++) total+=high[i];
    cout<<root+1LL<<"\n"<<total;
    return 0;
}
