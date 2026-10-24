#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using ll=long long;
using namespace std;
ll m;
vector<pair<ll,ll>> line={{0LL,0LL}};
bool vers(const pair<ll,ll>& A,const pair<ll,ll>& B)
{
    if (A.first!=B.first) return A.first<B.first;
    else return A.second>B.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin>>t;
    for (ll tt=1LL;tt<=t;tt++)
    {
        cin>>m;
        line.resize(m+1LL);
        for (ll i=1LL;i<=m;i++) cin>>line[i].first>>line[i].second;
        sort(line.begin(),line.end(),vers);
        vector<ll> tails={};
        for (ll i=1LL;i<=m;i++)
        {
            auto it=lower_bound(tails.begin(),tails.end(),line[i].second);
            if (it==tails.end()) tails.push_back(line[i].second);
            else *it=line[i].second;
        }
        cout<<(ll)tails.size()<<"\n";
    }
    return 0;
}
