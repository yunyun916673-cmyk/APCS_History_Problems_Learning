#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <utility>
using ll=long long;
using namespace std;
struct DP
{
    ll n,SUM;
    vector<ll> A;
    vector<vector<ll>> dp;
    DP(ll test)
    {
        n=test; SUM=0LL;
        A.resize(n+1LL,0LL);
        for (ll i=1LL;i<=n;i++) {cin>>A[i];SUM+=A[i];}
        dp.resize(n+1LL,vector<ll> (n+1LL,0LL));
        for (ll i=1LL;i<=n;i++) dp[i][i]=A[i];
    }
    void RUN()
    {
        for (ll len=2LL;len<=n;len++)
        {
            for (ll i=1LL;i+len-1LL<=n;i++)
            {
                ll j=i+len-1LL;
                dp[i][j]=max(A[i]-dp[i+1LL][j],A[j]-dp[i][j-1LL]);
            }
        }
    }
    pair<ll,ll> get_ans() {ll a=(SUM+dp[1LL][n])/2LL;ll b=SUM-a;return make_pair(a,b);}
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n; DP temp(n); temp.RUN();
    cout<<temp.get_ans().first<<' '<<temp.get_ans().second<<'\n';
    return 0;
}
