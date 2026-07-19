#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using ll=long long;
using namespace std;
using pll= pair<ll,ll>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<pll> all(n);
    for (ll i=0;i<n;i++)
        cin>>all[i].first>>all[i].second;
    sort(all.begin(),all.end());
    vector<pll> tmp;
    tmp.push_back({all[0].first,all[0].second});
    for (ll i=1;i<n;i++)
    {
        auto [li,ri]=all[i];
        ll plus=ri-li; if(!plus) continue;
        auto &[left,right]=tmp.back();
        if (li<=right)
        {
            if (ri>right) right=ri;
        }
        else tmp.push_back({li,ri});
    }
    ll ans=0;
    for (auto [lf,rf]:tmp)
        ans+=rf-lf;
    cout<<ans;
    return 0;
}
