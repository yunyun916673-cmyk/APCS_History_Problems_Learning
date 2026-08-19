#include <iostream>
#include <unordered_map>
#include <algorithm>
using ll=long long;
using namespace std;
unordered_map<ll,ll> temp;
ll getting(ll c)
{
    if (temp.count(c)) return temp[c];
    return c+1LL;
}
void moving(ll a,ll b)
{
    ll cura=getting(a);
    ll curb=getting(b);
    temp[a]=curb;
    temp[b]=cura;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin>>n>>m;
    ll ans=0LL;
    for (ll i=0LL;i<m;i++)
    {
        int t; cin>>t;
        if (t==1)
        {
            ll a,b; cin>>a>>b;
            moving(a-1LL,b-1LL);
        }
        else
        {
            ll c; cin>>c;
            ans+=getting(c-1LL);
        }
    }
    cout<<ans;
    return 0;
}
