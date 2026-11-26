#include <iostream>
#include <bitset>
#include <algorithm>
#include <climits>
using ll=long long;
using namespace std;
ll m,n;
bitset<1800005> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    ll ans=LLONG_MAX/4LL;
    ll lst=0LL,nst=1LL;
    dp[0LL]=1;
    for (ll i=1LL;i<=n;i++)
    {
        ll cnt; cin>>cnt;
        if (cnt>=m) ans=min(ans,cnt);
        else dp|=(dp<<cnt);
    }
    for (ll i=m;i<=2*m;i++) if (dp[i]) {ans=min(ans,i);break;}
    cout<<ans-m<<'\n'; return 0;
}
