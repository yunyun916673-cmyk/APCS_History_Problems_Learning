#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using ll=long long;
using namespace std;
const ll INF=LLONG_MAX/4LL;
ll N,M;
ll Z() {ll ans=0LL;for(ll i=1LL;i<=N;i++){ll x;cin>>x;ans+=x;}return ans;}
ll A()
{
    vector<ll> line(N+1LL,0LL);
    for (ll i=1LL;i<=N;i++) cin>>line[i];
    sort(line.begin()+1,line.end(),greater<ll>());
    ll ans=0LL;
    for (ll i=1LL;i<=N;i++) if (i%3LL) ans+=line[i];
    return ans;
}
ll B()
{
    vector<ll> line(N+1LL,0LL);
    for (ll i=1LL;i<=N;i++) cin>>line[i];
    sort(line.begin()+1,line.end(),greater<ll>());
    ll ans=0LL;
    for (ll i=1LL;i<=N;i++) if (i%5LL!=4LL&&i%5LL!=0LL) ans+=line[i];
    return ans;
}
ll C() {ll P;cin>>P;P=100LL-P;return (Z()*P+99LL)/100LL;}
ll AB()
{
    vector<ll> line(N+1LL,0LL);
    for (ll i=1LL;i<=N;i++) {cin>>line[i];line[i]*=100LL;}
    sort(line.begin()+1,line.end(),greater<ll>());
    vector<ll> dp(N+1LL,INF); dp[0LL]=0LL;
    for (ll i=1LL;i<=N;i++)
    {
        dp[i]=min(dp[i],dp[i-1LL]+line[i]);
        if (i-3LL>=0LL) dp[i]=min(dp[i],dp[i-3LL]+line[i-2LL]+line[i-1LL]);
        if (i-5LL>=0LL) dp[i]=min(dp[i],dp[i-5LL]+line[i-4LL]+line[i-3LL]+line[i-2LL]);
    }
    return (dp[N]+99LL)/100LL;
}
ll AC()
{
    ll P; cin>>P;P=100LL-P;
    vector<ll> line(N+1LL,0LL);
    for (ll i=1LL;i<=N;i++) {cin>>line[i];line[i]*=100LL;}
    sort(line.begin()+1,line.end(),greater<ll>());
    vector<ll> dp(N+1LL,INF); dp[0LL]=0LL;
    for (ll i=1LL;i<=N;i++)
    {
        dp[i]=min({dp[i],dp[i-1LL]+line[i],dp[i-1LL]+line[i]*P/100LL});
        if (i-3LL>=0LL) dp[i]=min(dp[i],dp[i-3LL]+line[i-2LL]+line[i-1LL]);
    }
    return (dp[N]+99LL)/100LL;
}
ll ABC()
{
    ll P; cin>>P;P=100LL-P;
    vector<ll> line(N+1LL,0LL);
    for (ll i=1LL;i<=N;i++) {cin>>line[i];line[i]*=100LL;}
    sort(line.begin()+1,line.end(),greater<ll>());
    vector<ll> dp(N+1LL,INF); dp[0LL]=0LL;
    for (ll i=1LL;i<=N;i++)
    {
        dp[i]=min({dp[i],dp[i-1LL]+line[i],dp[i-1LL]+line[i]*P/100LL});
        if (i-3LL>=0LL) dp[i]=min(dp[i],dp[i-3LL]+line[i-2LL]+line[i-1LL]);
        if (i-5LL>=0LL) dp[i]=min(dp[i],dp[i-5LL]+line[i-4LL]+line[i-3LL]+line[i-2LL]);
    }
    return (dp[N]+99LL)/100LL;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;ll ans=-1LL;
    if (M==0LL) ans=Z();
    else if (M==1LL) ans=A();
    else if (M==2LL) ans=B();
    else if (M==3LL) ans=C();
    else if (M==4LL) ans=AB();
    else if (M==5LL) ans=AC();
    else if (M==6LL) ans=ABC();
    cout<<ans<<'\n'; return 0;
}
