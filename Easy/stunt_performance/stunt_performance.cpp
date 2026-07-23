#include <iostream>
#include <algorithm>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; 
    cin>>n;
    ll buil[n];
    for (ll i=0;i<n;i++) 
        cin>>buil[i];
    ll cnt=1;
    ll ans=1;
    for (ll i=1;i<n;i++)
    {
        if (buil[i]<buil[i-1]）
    {
        cnt++;
        ans=max(ans,cnt);
    }
        else cnt=1;
    }
    cout<<ans;
    return 0;
}
