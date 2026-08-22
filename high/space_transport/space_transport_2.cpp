#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <set>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,m,p;
vector<ll> sgt;
vector<pair<ll,ll>> org;
unordered_map<ll,ll> trans;
ll MOD(ll x) {return (x%p+p)%p;}
ll update(ll pos,ll L,ll R,ll P,ll val)
{
    if (P<L||P>R) return 0LL;
    if (L==R)
    {
        sgt[pos]=MOD(sgt[pos]+val);
        return MOD(val);
    }
    ll mid=(L+R)/2LL;
    ll cnt=pos*2LL;
    ll cur=MOD(update(cnt,L,mid,P,val)+update(cnt+1LL,mid+1LL,R,P,val));
    sgt[pos]=MOD(sgt[pos]+cur);
    return cur;
}
ll query(ll pos,ll L,ll R,ll left,ll right)
{
    if (right<L||left>R) return 0LL;
    if (left<=L&&right>=R) return sgt[pos];
    ll mid=(L+R)/2LL;
    ll cnt=2LL*pos;
    return MOD(query(cnt,L,mid,left,right)+query(cnt+1LL,mid+1LL,R,left,right));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>p;
    org.resize(n+1LL);
    set<ll> cursor;
    cursor.insert(0LL);
    cursor.insert(m);
    org[0LL]={-1e18,-1e18};
    for (ll i=1LL;i<=n;i++)
    {
        ll x; cin>>x;
        org[i].second=x;
        cursor.insert(x);
    }
    for (ll i=1LL;i<=n;i++)
    {
        ll x; cin>>x;
        org[i].first=x;
        cursor.insert(x);
    }
    ll sz=(ll)cursor.size();
    sgt.assign(4*sz,0LL);
    ll c=1LL;
    for (ll cur:cursor) {trans[cur]=c;c++;}
    update(1LL,1LL,sz,trans[0LL],1LL);
    sort(org.begin(),org.end());
    for (ll i=1LL;i<=n;i++)
    {
        auto &[right,left]=org[i];
        ll cnt=query(1LL,1LL,sz,trans[left],trans[right]-1LL);
        update(1LL,1LL,sz,trans[right],cnt);
    }
    cout<<query(1LL,1LL,sz,trans[m],trans[m]);
    return 0;
}
