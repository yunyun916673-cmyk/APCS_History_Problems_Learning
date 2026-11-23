#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<ll> line(n);
    for (ll i=0LL;i<n;i++) cin>>line[i];
    ll ans=0LL;
    for (ll i=0LL;i<n;i++) for (ll j=i+1LL;j<n;j++)
    if (line[i]>line[j]) ans++;
    cout<<ans<<'\n'; return 0;
}
