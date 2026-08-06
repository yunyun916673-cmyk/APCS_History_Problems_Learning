#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<pair<ll,ll>> temp(n);
    for (ll i=0;i<n;i++)
    {
        ll x,y; cin>>x>>y;
        temp[i]={x,y};
    }
    sort(temp.begin(),temp.end());
    vector<ll> dp(n,1LL);
    ll ans=0LL;
    for (ll i=0;i<n;i++)
    {
        ll test=temp[i].second;
        for (ll j=i-1LL;j>=0;j--)
        {
            if (test>=temp[j].second)
                dp[i]=max(dp[i],dp[j]+1LL);
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
