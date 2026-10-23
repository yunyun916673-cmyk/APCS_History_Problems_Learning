#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>n>>k;
    vector<ll> line(n+1LL,0LL);
    for (ll i=1LL;i<=n;i++) cin>>line[i];
    vector<ll> L(n+1LL,0LL); L[0LL]=1LL;
    vector<ll> last_pos(100005LL,0LL);
    for (ll i=1LL;i<=n;i++)
    {
        L[i]=max(L[i-1LL],last_pos[line[i]]+1LL);
        last_pos[line[i]]=i;
    }
    vector<vector<ll>> dp(2LL,vector<ll> (n+1LL,0LL));
    ll lst=0LL,nst=1LL;
    for (ll i=1LL;i<=k;i++)
    {
        for (ll j=1LL;j<=n;j++)
            dp[nst][j]=max(dp[nst][j-1LL],dp[lst][L[j]-1LL]+j-L[j]+1LL);
        swap(lst,nst);
    }
    cout<<dp[lst][n]<<"\n"; return 0;
}
