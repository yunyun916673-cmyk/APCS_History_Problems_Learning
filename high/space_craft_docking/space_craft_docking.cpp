#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,k,ans=0LL; vector<pair<ll,ll>> act;
multiset<pair<ll,ll>> temp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin>>n>>k; 
    act.resize(n);
    for (ll i=0LL;i<n;i++) cin>>act[i].second;
    for (ll i=0LL;i<n;i++) cin>>act[i].first;
    sort(act.begin(),act.end());
    for (ll i=0LL;i<k;i++) temp.insert({-1LL,i});
    for (ll i=0LL;i<n;i++)
    {
        auto &[right,left]=act[i];
        auto it=temp.upper_bound({left,-1LL});
        if (it==temp.begin()) continue; --it; ans++;
        ll typ=(*it).second; temp.erase(it);
        temp.insert({right,typ});
    } cout<<ans; return 0;
}
