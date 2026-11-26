#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin>>n>>m;
    vector<vector<ll>> dp(m+1LL,vector<ll> (2LL,0LL));
    dp[0LL][0LL]=1LL;
    for (int i=1LL;i<=m;i++)
    {
        dp[i][0LL]=dp[i-1LL][1LL]+dp[i-1LL][0LL];
        for (int k=1LL;k<=n&&i-k>=0LL;k++)
        {
            dp[i][1LL]+=dp[i-k][0LL];
        }
    }
    cout<<dp[m][0LL]+dp[m][1LL]<<'\n'; return 0;
}
