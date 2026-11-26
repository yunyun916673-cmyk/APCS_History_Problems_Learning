#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using ll=long long;
using namespace std;
bool vers(const pair<ll,ll>& a,const pair<ll,ll>& b)
{if (a.first!=b.first) return a.first<b.first; return a.second>b.second;}
struct DP
{
    ll m;
    vector<pair<ll,ll>> line;
    vector<ll> tails;
    DP(ll test)
    {
        m=test;
        line.resize(m+1LL);
        for (ll i=1LL;i<=m;i++) cin>>line[i].first>>line[i].second;
        sort(line.begin(),line.end(),vers);
    };
    void LIS()
    {
        tails={};
        for (ll i=1LL;i<=m;i++)
        {
            auto it=lower_bound(tails.begin(),tails.end(),line[i].second);
            if (it==tails.end()) tails.push_back(line[i].second);
            else *it=line[i].second;
        }
    }
    ll get_ans() {return (ll)tails.size();}
    
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin>>t;
    while (t--)
    {
        ll m; cin>>m;
        DP temp(m);
        temp.LIS();
        cout<<temp.get_ans()<<'\n';
    }
    return 0;
}
