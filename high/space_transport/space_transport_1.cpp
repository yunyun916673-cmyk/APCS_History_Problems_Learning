#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_map>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,m,p,sz;
vector<pair<ll,ll>> org;
unordered_map<ll,ll> trans;
vector<ll> bit;
ll MOD(ll x) {return (x%p+p)%p;}
ll lowbit(ll x) {return x&(-x);}
void update(ll x,ll val)
{
    while (x<=sz)
    {
        bit[x]=MOD(bit[x]+val);
        x+=lowbit(x);
    }
    return;
}
ll query(ll x)
{
    ll ans=0LL;
    while (x>0LL)
    {
        ans+=bit[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>p; org.resize(n+1LL);
    set<ll> cursor;
    cursor.insert(0LL); cursor.insert(m);
    for (ll i=1LL;i<=n;i++)
    {
        ll x; cin>>x; org[i].second=x;
        cursor.insert(x);
    }
    for (ll i=1LL;i<=n;i++)
    {
        ll x; cin>>x; org[i].first=x;
        cursor.insert(x);
    }
    sz=(ll)cursor.size();
    bit.assign(sz+1LL,0LL); update(1LL,1LL);
    int c=1LL;
    for (ll cur:cursor) {trans[cur]=c;c++;}
    org[0LL]={-1e18,-1e18};
    sort(org.begin(),org.end());
    for (ll i=1LL;i<=n;i++)
    {
        auto &[right,left]=org[i];
        ll cnt=MOD(query(trans[right]-1LL)-query(trans[left]-1LL));
        update(trans[right],cnt);
    }
    cout<<(query(trans[m])-query(trans[m]-1LL));
    return 0;
}
