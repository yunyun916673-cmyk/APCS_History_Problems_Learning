#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<ll> H(n+1LL,LLONG_MAX/4LL),P(n+1LL,0LL);
    for (ll i=1LL;i<=n;i++) cin>>H[i];
    for (ll j=1LL;j<=n;j++) cin>>P[j];
    ll ans=0LL; vector<ll> temp={0LL};
    for (ll i=1LL;i<=n;i++)
    {
        ll left=0LL,right=(ll)temp.size()-1LL;
        ll cnt=0LL;ll cur=H[i]+P[i];
        while (left<=right)
        {
            ll mid=(left+right)/2LL;
            if (H[temp[mid]]>cur) {left=mid+1LL;cnt=mid;}
            else right=mid-1LL;
        }
        ans+=i-temp[cnt]-1LL;
        while (!temp.empty()&&H[temp.back()]<=H[i]) temp.pop_back();
        temp.push_back(i);
    }
    cout<<ans<<'\n'; return 0;
}
