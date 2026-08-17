#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,k; vector<ll> H,W;
bool check(ll ove)
{
    ll tag=0LL,cnt=0LL;
    for (ll i=0LL;i<n;i++)
    {
        if (H[i]>=ove) {cnt++;continue;}
        bool kepp=true;
        while (kepp)
        {
            if (cnt>=W[tag])
            {cnt-=W[tag];tag++;}
            else {kepp=false; cnt=0LL;}
            if (tag==k) return true;
        }
    } return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin>>n>>k;
    H.resize(n); W.resize(k);
    ll topp=0LL;
    for (ll i=0LL;i<n;i++)
    {ll x; cin>>x; H[i]=x;topp=max(topp,x);}
    for (ll i=0LL;i<k;i++) cin>>W[i];
    ll left=0LL,right=topp;ll ans=right;
    while (left<=right)
    {
        ll mid=(left+right)/2LL;
        if (check(mid)) {right=mid-1LL;ans=mid;}
        else left=mid+1LL;
    } cout<<ans; return 0;
}
