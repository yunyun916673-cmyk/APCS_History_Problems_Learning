#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<vector<ll>> dp(2*n+5LL,vector<ll> (n+5LL,0LL));
    dp[0LL][0LL]=1LL;dp[1LL][1LL]=1LL;
    for (ll i=2LL;i<=2*n;i++)
    {
        for (ll j=0LL;j<=n;j++)
        {
            if (j>0LL) dp[i][j]+=dp[i-1LL][j-1LL];
            if (j<n) dp[i][j]+=dp[i-1LL][j+1LL];
        }
    }
    cout<<dp[2*n][0LL]<<'\n'; return 0;
}
