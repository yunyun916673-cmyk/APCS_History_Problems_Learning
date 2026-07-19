#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,k;
vector<ll> points;
bool check(ll Rad)
{
    ll used=0;
    ll i=0;
    while (i<n)
    {
        used++;
        if (used>k) return false;
        ll cnt=points[i]+Rad;
        while (i<n && points[i]<=cnt) i++;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for (ll i=0;i<n;i++)
    { ll x; cin>>x; points.push_back(x); }
    sort(points.begin(),points.end());
    ll left=1,right=points[n-1LL]-points[0],ans=right;
    while (left<=right)
    {
        ll mid=(left+right)/2;
        if (check(mid))
        { ans=mid; right=mid-1LL;}
        else left=mid+1LL;
    }
    cout<<ans<<"\n";
    return 0;
}
