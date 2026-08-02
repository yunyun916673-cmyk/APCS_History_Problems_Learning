#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,m;
vector<ll> come;
ll total=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    come.resize(n);
    for (ll i=0;i<n;i++) cin>>come[i];
    sort(come.begin(),come.end());
    for (ll i=0;i<m;i++)
    {
        ll s,e; cin>>s>>e;
        auto lit=lower_bound(come.begin(),come.end(),s);
        auto rit=upper_bound(come.begin(),come.end(),e);
        total+=(rit-come.begin())-(lit-come.begin());
    }
    cout<<total;
    return 0;
}