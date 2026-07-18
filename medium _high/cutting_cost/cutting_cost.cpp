#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,L;
multiset<ll> wascut;
ll cost=0;
void cutting(ll pos)
{
    ll left=-1,right=L+1;
    auto l_it=wascut.lower_bound(pos);
    auto r_it=wascut.upper_bound(pos);
    if (l_it==wascut.begin()) left=0;
    else { --l_it; left=*l_it; }
    if (r_it==wascut.end()) right=L;
    else right=*r_it;
    cost+=right-left;
    wascut.insert(pos);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>L;
    vector<ll> org_cut(n);
    for (ll i=0;i<n;i++)
    {
        ll xi,ii; cin>>xi>>ii;
        org_cut[ii-1LL]=xi;
    }
    for (ll i=0;i<n;i++)
    {
        ll pos=org_cut[i];
        cutting(pos);
    }
    cout<<cost;
    return 0;
}
