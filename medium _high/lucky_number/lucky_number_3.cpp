#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using ll=long long;
using namespace std;
const ll INF=1e18;
ll n;
vector<ll> line;
vector<ll> Pt;
vector<ll> sgt;
unordered_map<ll,ll> temp;
ll build(ll pwd,ll left,ll right)
{
    if (left==right)
    {
        sgt[pwd]=line[left];
        return line[left];
    }
    ll mid=(left+right)/2; ll cnt=pwd*2LL;
    sgt[pwd]=min(build(cnt,left,mid),build(cnt+1LL,mid+1LL,right));
    return sgt[pwd];
}
ll query(ll pwd,ll left,ll right,ll L,ll R)
{
    if (left>R || right<L) return INF;
    if (R>=right && L<=left) return sgt[pwd];
    ll mid=(left+right)/2; ll cnt=pwd*2LL;
    return min(query(cnt,left,mid,L,R),query(cnt+1LL,mid+1LL,right,L,R));
}
ll simul(ll left,ll right)
{
    while (left<right)
    {
        ll mid=temp[query(1LL,1LL,n,left,right)];
        if (Pt[mid]-Pt[left-1LL]>Pt[right]-Pt[mid-1LL])
            right=mid-1LL;
        else left=mid+1LL;
    }
    return line[left];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n; sgt.assign(4*n,INF);
    line.resize(n+1LL);
    Pt.resize(n+1LL);
    for (ll i=1;i<=n;i++)
    {
        ll x; cin>>x;
        line[i]=x; temp[x]=i;
        Pt[i]=x;
        if (i==1) continue;
        Pt[i]+=Pt[i-1LL];
    }
    build(1LL,1LL,n);
    cout<<simul(1LL,n);
    return 0;
}
