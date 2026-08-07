#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using ll=long long;
using namespace std;
ll n;
vector<ll> bit;
ll lowbit(ll x) {return x&(-x);}
void update(ll x,ll val)
{
    while (x<=2*n)
    {
        bit[x]+=val;
        x+=lowbit(x);
    }
    return;
}
ll query(ll x)
{
    ll total=0LL;
    while (x>0)
    {
        total+=bit[x];
        x-=lowbit(x);
    }
    return total;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<pair<ll,ll>> temp(n+1LL,{0,0});
    for (ll i=1;i<=2*n;i++)
    {
        ll x; cin>>x;
        if (temp[x].first) temp[x].second=i;
        else temp[x].first=i;
    }
    bit.assign(2*n+1LL,0LL);
    ll ans=0LL;
    for (ll i=1;i<=n;i++)
    {
        ll left=temp[i].first,right=temp[i].second;
        if (left>right) swap(left,right);
        ans+=query(right)-query(left);
        update(left,1LL); update(right,1LL);
    }
    cout<<ans;
    return 0;
}
