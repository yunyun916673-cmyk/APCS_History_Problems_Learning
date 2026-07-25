#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using ll=long long;
using namespace std;
ll m,n;
unordered_map<string,ll> part;
vector<string> all;
ll is_m()
{
    if ((ll)part.size()==m) return 1;
    else return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    all.resize(n);
    for (ll i=0;i<n;i++) cin>>all[i];
    for (ll i=0;i<m;i++) part[all[i]]+=1LL;
    ll total=is_m();
    for (ll i=0;i+m<n;i++)
    {
        part[all[i]]--;
        if (!part[all[i]]) part.erase(all[i]);
        part[all[i+m]]+=1LL;
        total+=is_m();
    }
    cout<<total;
    return 0;
}
