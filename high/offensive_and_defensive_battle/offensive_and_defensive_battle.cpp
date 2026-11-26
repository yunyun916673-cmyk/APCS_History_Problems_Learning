#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll DP(const ll& m,const ll& n,const vector<ll>& A)
{
    vector<ll> dp(m+1LL,0LL);
    ll ans=0LL;
    for (ll i=1LL;i<=m;i++)
    {
        for (ll j=1LL;(!dp[i])&&j<=n&&i-A[j]>=0LL;j++)
            dp[i]=(dp[i]||(!dp[i-A[j]]));
        ans+=dp[i];
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m,n; cin>>m>>n;
    vector<ll> A(n+1LL,0LL);
    for (ll i=1LL;i<=n;i++) cin>>A[i];
    sort(A.begin(),A.end());
    cout<<DP(m,n,A)<<'\n'; return 0;
}
