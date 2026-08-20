#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using ll=long long;
using namespace std;
ll n,m,r,k,t;
unordered_map<ll,ll> hums_to_class;
unordered_map<ll,ll> hums_to_ath;
vector<ll> cnt;
ll tag=1LL;
vector<bool> oftt;
vector<ll> hums;
void dfs(ll pos)
{
    if ((ll)hums.size()==k)
    {
        if (tag==t)
        {
            for (ll hum:hums)
                cout<<hum<<" ";
            exit(0);
        }
        tag++;
        return;
    }
    for (ll i=pos;i<=m*r;i++)
    {
        ll ath=hums_to_ath[i];
        ll css=hums_to_class[i];
        if (!oftt[ath]&&cnt[css]<2LL)
        {
            oftt[ath]=true;
            hums.push_back(i);
            cnt[css]++;
            dfs(i+1LL);
            oftt[ath]=false;
            hums.pop_back();
            cnt[css]--;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>r>>k>>t;
    ll c=1LL;
    cnt.assign(m+1LL,0LL);
    oftt.assign(n+1LL,false);
    for (ll i=1LL;i<=m*r;i+=r)
    {
        for (ll j=i;j<i+r;j++)
        {
            hums_to_class[j]=c;
            cin>>hums_to_ath[j];
        }
        c++;
    }
    dfs(1LL);
    return 0;
}
