#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
struct dat {ll W,V,C;};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<dat> line(n+1LL);
    for (ll i=1LL;i<=n;i++) cin>>line[i].W>>line[i].V>>line[i].C;
    ll t; cin>>t;
    vector<ll> dp(t+1LL,0LL);
    for (ll i=1LL;i<=n;i++)
    {
        ll c=line[i].C,p=1LL;
        while (c>0LL)
        {
            ll k=min(p,c);
            c-=k;p*=2LL;
            ll w=line[i].W,v=line[i].V;
            for (ll j=t;j>=k*w;j--) dp[j]=max(dp[j],dp[j-k*w]+k*v);
        }
    }
    cout<<dp[t]<<'\n'; return 0;
}
