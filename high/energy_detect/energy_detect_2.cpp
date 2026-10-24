#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using ll=long long;
using namespace std;
using pll=pair<ll,ll>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<pll> temp(n+1LL,make_pair(0LL,0LL));
    for (ll i=1LL;i<=n;i++) cin>>temp[i].first>>temp[i].second;
    sort(temp.begin(),temp.end());
    vector<ll> line(n+1LL);
    for (ll i=0LL;i<=n;i++) line[i]=temp[i].second;
    vector<ll> tails={};
    for (ll i=1LL;i<=n;i++)
    {
        auto it=upper_bound(tails.begin(),tails.end(),line[i]);
        if (it==tails.end()) tails.push_back(line[i]);
        else *it=line[i];
    }
    cout<<(ll)tails.size()<<"\n"; return 0;
}
