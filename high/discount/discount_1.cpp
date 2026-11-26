#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using ll=long long;
using namespace std;
ll m,n;
vector<ll> A;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n; A.resize(n+1LL,0LL);
    for (ll i=1LL;i<=n;i++) cin>>A[i];
    sort(A.begin(),A.end());
    ll ans=LLONG_MAX/4LL;
    vector<vector<bool>> dp(2LL,vector<bool> (m+1LL,false));
    ll lst=0LL,nst=1LL;
    for (ll i=1LL;i<=n;i++)
    {
        dp[nst]=dp[lst];
        ll cnt=A[i];
        if (cnt>=m) {ans=min(ans,cnt);continue;}
        dp[nst][cnt]=true;
        for (ll j=1LL;j<=m;j++)
        {
            if (!dp[lst][j]) continue;
            if (j+cnt>=m) ans=min(ans,j+cnt);
            else dp[nst][j+cnt]=true;
        }
        swap(lst,nst);
    }
    cout<<ans-m<<'\n'; return 0;
}
