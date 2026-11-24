#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using ll=long long;
using namespace std;
const ll INF=LLONG_MAX/4LL;
ll n; vector<ll> H,P;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>n;
    H.resize(n+1LL,INF);
    P.resize(n+1LL,0LL);
    for (ll i=1LL;i<=n;i++) cin>>H[i];
    for (ll i=1LL;i<=n;i++) cin>>P[i];
    ll ans=0LL;
    vector<ll> temp={0LL};
    for (ll i=1LL;i<=n;i++)
    {
        ll cur=H[i]+P[i];
        auto it=upper_bound(temp.begin(),temp.end(),cur,
        [&](ll val,ll idx){return val>=H[idx];}); --it;
        ans+=i-*it-1LL;
        while (!temp.empty()&&H[temp.back()]<=H[i]) temp.pop_back();
        temp.push_back(i);
    }
    cout<<ans<<'\n'; return 0;
}
