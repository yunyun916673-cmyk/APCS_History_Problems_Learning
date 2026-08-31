#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    vector<ll> dp(41LL,0LL);
    dp[0LL]=1LL;dp[1LL]+=1LL;dp[2LL]+=5LL;
    for (ll i=3LL;i<=40LL;i++)
            dp[i]=dp[i-1LL]+dp[i-2LL]*4LL+dp[i-3LL]*2LL;
    int n;
    for (ll s=0;s<t;s++) {cin>>n;cout<<dp[n]<<"\n";}
    return 0;
}
