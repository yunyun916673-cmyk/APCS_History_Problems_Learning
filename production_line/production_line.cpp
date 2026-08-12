#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using ll=long long;
using namespace std;
ll n,m;
vector<ll> bit;
ll lowbit(ll x) {return x&(-x);}
void update(ll x,ll val)
{
    while (x<=n)
    {bit[x]+=val;x+=lowbit(x);}
    return;
}
ll query(ll x)
{
    ll ans=0LL;
    while (x>0LL)
    {ans+=bit[x];x-=lowbit(x);}
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    bit.assign(n+1LL,0LL);
    for (ll i=1;i<=m;i++)
    {
        ll l,r,w; cin>>l>>r>>w;
        update(l,w);if (r!=n) update(r+1LL,-w);
    }
    priority_queue<ll,vector<ll>> missions;
    for (ll i=2;i<=n+1LL;i++)
    {
        ll cnt=query(i-1LL);
        missions.push(cnt);
    }
    priority_queue<ll,vector<ll>,greater<ll>> workers;
    for (ll i=1;i<=n;i++)
    {ll t; cin>>t; workers.push(t);}
    ll total=0LL;
    while (!missions.empty())
    {
        ll msn=missions.top(); missions.pop();
        ll wkr=workers.top(); workers.pop();
        total+=msn*wkr;
    }
    cout<<total;
    return 0;
}