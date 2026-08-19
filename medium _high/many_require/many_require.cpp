#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,m,q,ans=0LL;
vector<tuple<ll,ll,ll,ll>> temp;
void check(vector<ll> &oftt)
{
    ll curr=0LL;
    for (auto [a,b,c,d]:temp)
    {
        if (oftt[b]-oftt[a]==c)
            curr+=d;
    }
    ans=max(ans,curr);
    return;
}
void tryy(vector<ll> &s,ll pos)
{
    if ((ll)s.size()==n)
    {
        check(s);
        return;
    }
    for (ll i=pos;i<=m;i++)
    {
        s.push_back(i);
        tryy(s,i);
        s.pop_back();
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>n>>m>>q;
    for (ll i=0LL;i<q;i++)
    {
        ll a,b,c,d; cin>>a>>b>>c>>d;
        a--; b--;
        temp.push_back({a,b,c,d});
    }
    vector<ll> ttfo={};
    tryy(ttfo,1LL);
    cout<<ans;
    return 0;
}
