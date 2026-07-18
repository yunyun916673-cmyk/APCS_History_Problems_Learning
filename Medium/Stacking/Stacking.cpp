#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
struct thing
{ ll w,f; };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<thing> all(n);
    for (ll i=0;i<n;i++) cin>>all[i].w;
    for (ll i=0;i<n;i++) cin>>all[i].f;
    auto swapping=[](const thing &a,const thing &b)
    { return a.w*b.f<b.w*a.f; };
    sort(all.begin(),all.end(),swapping);
    ll sum_=0;
    ll weight=0;
    for (auto &test:all)
    {
        sum_+=weight*test.f;
        weight+=test.w;
    }
    cout<<sum_<<"\n";
    return 0;
}
