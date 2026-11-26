#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
ll MOD(ll x) {return (x+1000000007)%1000000007;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<ll> dp(n+1LL,0LL);
    dp[0LL]=1LL;
    ll pre=0LL;
    for (ll i=1LL;i<=n;i++)
    {
        if (i-1LL>=0LL) dp[i]=MOD(dp[i]+dp[i-1LL]);
        if (i-2LL>=0LL) dp[i]=MOD(dp[i]+dp[i-2LL]);
        if (i-3LL<0LL) continue;
        pre+=2*dp[i-3LL]; dp[i]=MOD(dp[i]+pre);
    }
    cout<<dp[n]<<'\n'; return 0;
}
