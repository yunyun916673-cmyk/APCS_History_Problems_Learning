#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k; cin>>n>>k; ll ans=0LL;
    vector<ll> line(n+1LL),vec(n+1LL);
    ll lag=0LL;
    for (ll i=1LL;i<=n;i++)
    {
        ll x; cin>>x;
        line[i]=x; lag+=x;
        if (x%2LL) vec[i]=1LL;
        else vec[i]=-1LL;
    }
    k=min(k,lag);
    vector<ll> P(n+1LL,0LL),S(n+1LL,0LL);
    P[1LL]=line[1LL]; S[1LL]=line[n];
    for (ll i=2LL;i<=n;i++) P[i]+=P[i-1LL]+line[i];
    for (ll i=2LL;i<=n;i++) S[i]+=S[i-1LL]+line[n-i+1LL];
    vector<ll> preffix(n+1LL,0LL),suffix(n+1LL,0LL);
    unordered_map<ll,vector<ll>> temp;
    preffix[1LL]=vec[1LL]; suffix[1LL]=vec[n];
    for (ll i=2LL;i<=n;i++)
    {
        ll x=preffix[i-1LL]+vec[i];
        preffix[i]+=x;
    }
    for (ll i=2LL;i<=n;i++)
    {
        ll x=suffix[i-1LL]+vec[n-i+1LL];
        suffix[i]+=x;
    }
    for (ll i=0LL;i<=n;i++)
        temp[suffix[i]].push_back(S[i]);
    for (ll i=0LL;i<=n;i++)
    {
        ll cur=preffix[i]; ll left=P[i];
        ll lim=min(k-left,S[n-i]);
        auto it=upper_bound(temp[-cur].begin(),temp[-cur].end(),lim);
        if (it==temp[-cur].begin()) continue; --it;
        ans=max(ans,*it+left);
    }
    cout<<ans; return 0;
}
