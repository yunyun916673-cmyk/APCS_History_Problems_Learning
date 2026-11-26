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
    vector<ll> T;
    vector<vector<ll>> dp;
    ll D(ll t,ll p1,ll p2)
    {
        ll dist=abs(p1-p2);
        return (T[p2]-(dist+t)%T[p2])%T[p2]+dist;
    }
    DP(ll test)
    {
        n=test;
        T.resize(n+1LL,0LL);
        dp.resize((1LL<<n),vector<ll> (n+1LL,INF));
        for (ll i=1LL;i<=n;i++) cin>>T[i];
        for (ll i=1LL;i<=n;i++) dp[1LL<<(i-1LL)][i]=D(0LL,0LL,i);
    }
    void func()
    {
        for (ll mask=0LL;mask<(1LL<<n);mask++)
            for (ll i=1LL;i<=n;i++)//已經下載
                for (ll j=1LL;j<=n;j++)//未下載
                    if ((mask&(1LL<<(i-1LL)))&&(!(mask&(1LL<<(j-1LL))))&&dp[mask][i]!=INF)
                        dp[mask|(1LL<<(j-1LL))][j]=min(dp[mask|(1LL<<(j-1LL))][j],
                        dp[mask][i]+D(dp[mask][i],i,j));
    }
    ll get_ans()
    {
        ll ans=INF;
        for (ll i=1LL;i<=n;i++) ans=min(ans,dp[(1LL<<n)-1LL][i]);
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n; DP temp(n); temp.func();
    cout<<temp.get_ans()<<'\n'; return 0;
}
