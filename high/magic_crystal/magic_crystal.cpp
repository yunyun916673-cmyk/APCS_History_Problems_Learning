#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
struct DP
{
    ll N,P;
    vector<ll> K;
    vector<ll> dp;
    DP(ll p1,ll p2)
    {
        N=p1;P=p2;
        K.resize(N+1LL,0LL);
        for (ll i=1LL;i<=N;i++) cin>>K[i];
        dp.resize(P+1LL,0LL); dp[0LL]=1LL;
        for (ll i=1LL;i<=N;i++)
            for (ll j=K[i];j<=P;j++)
                dp[j]+=dp[j-K[i]];
        cout<<dp[P]<<'\n';
    };
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,p; 
    while (cin>>n>>p&&!(n==0LL&&p==0LL)) DP(n,p);
    return 0;
}
