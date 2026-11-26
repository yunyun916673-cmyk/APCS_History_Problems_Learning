#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using ll=long long;
using namespace std;
const ll INF=LLONG_MAX/4LL;
struct DP
{
    ll n;
    vector<ll> A,dp;
    DP(ll test)
    {
        n=test;
        A.resize(n+1LL,0LL);
        for (ll i=1LL;i<=n;i++) cin>>A[i];
        dp.resize(n+1LL,INF);
        dp[1LL]=0LL;
        for (ll i=2LL;i<=n;i++) dp[i]=min(dp[i-1LL]+abs(A[i-1LL]-A[i]),dp[i-2LL]+abs(A[i-2LL]-A[i]));
        cout<<dp[n]<<'\n';
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin>>t;
    while (t--) {ll n;cin>>n;DP temp(n);}
    return 0;
}
