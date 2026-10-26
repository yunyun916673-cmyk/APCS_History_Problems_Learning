#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using ll=long long;
using namespace std;
ll N,M;
vector<ll> A={0LL},B={0LL};
bool check(ll X)
{
    vector<vector<bool>> dp(N+1LL,vector<bool> (M+1LL,false));
    dp[0LL][0LL]=true;
    for (ll i=0LL;i<=N;i++)
    {
        for (ll j=0LL;j<=M;j++)
        {
            ll cnt=A[i]+B[j];
            if (((i>0LL&&dp[i-1][j])||(j>0LL&&dp[i][j-1]))&&cnt>=0LL&&cnt<=X)
            {
                dp[i][j]=true;
            }
        }
    }
    return dp[N][M];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M; ll limt=0LL;
    for (ll i=1LL;i<=N;i++) {ll x;cin>>x;A.push_back(x);limt+=(x>0LL?x:0LL);}
    for (ll i=1LL;i<=M;i++) {ll x;cin>>x;B.push_back(x);limt+=(x>0LL?x:0LL);}
    for (ll i=2LL;i<=N;i++) A[i]+=A[i-1LL];
    for (ll i=2LL;i<=M;i++) B[i]+=B[i-1LL];
    if (A[N]+B[M]<0LL) {cout<<-1LL<<'\n';return 0;}
    ll left=0LL,right=limt+5LL;
    ll ans=right;
    while (left<=right)
    {
        ll mid=(left+right)/2LL;
        if (check(mid)) {right=mid-1LL;ans=mid;}
        else left=mid+1LL;
    }
    cout<<(ans>limt?-1LL:ans)<<'\n'; return 0;
}
