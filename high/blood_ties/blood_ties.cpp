#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
ll n;
vector<vector<ll>> grid;
ll pos=-1,mdist=-1;
void dfs(ll pwd,ll pnt,ll step)
{
    if (mdist<step)
    { mdist=step; pos=pwd; }
    for (ll kid:grid[pwd])
        if (kid!=pnt)
            dfs(kid,pwd,step+1LL);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    grid.resize(n);
    for (ll i=0;i<n-1LL;i++)
    {
        ll p,x; cin>>p>>x;
        grid[p].push_back(x);
        grid[x].push_back(p);
    }
    dfs(0,-1,0);
    ll cnt=pos;
    pos=-1,mdist=-1;
    dfs(cnt,-1,0);
    cout<<mdist;
    return 0;
}
