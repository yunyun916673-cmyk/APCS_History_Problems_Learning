#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using ll=long long;
using namespace std;
ll n;
multiset<ll> dist;
vector<ll> points;
vector<ll> bigans,smallans;
bool addpoints(ll x)
{
    vector<ll> needdists;
    vector<ll> removed;
    for (ll point:points)
        needdists.push_back(abs(x-point));
    for (ll nd:needdists)
    {
        auto it=dist.find(nd);
        if (it==dist.end())
        {
            for (ll rnd:removed)
                dist.insert(rnd);
            return false;
        }
        removed.push_back(nd);
        dist.erase(it);
    }
    points.push_back(x);
    return true;
}
void removedpoints(ll x)
{
    for (ll point:points)
    {
        if (point!=x)
            dist.insert(abs(x-point));
    }
    points.erase(find(points.begin(),points.end(),x));
}
void dfs(ll len)
{
    if (dist.empty())
    {
        vector<ll> cur=points;
        sort(cur.begin(),cur.end());
        if (bigans.empty() || bigans<cur)
            bigans=cur;
        if (smallans.empty() || smallans>cur)
            smallans=cur;
        return;
    }
    ll d=*dist.rbegin();
    if (d>0 && d<len)
    {
        if (addpoints(d))
        {
            dfs(len);
            removedpoints(d);
        }
    }
    ll od=len-d;
    if (od>0 && od<len && od!=d)
    {
        if (addpoints(od))
        {
            dfs(len);
            removedpoints(od);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    if (n==1)
    { cout<<0<<"\n"<<0; return 0; }
    ll m=n*(n-1)/2;
    ll bt=-1;
    for (ll i=0;i<m;i++)
    {
        ll t; cin>>t;
        dist.insert(t);
        bt=max(bt,t);
    }
    points.push_back(0);
    points.push_back(bt);
    dist.erase(dist.find(bt));
    dfs(bt);
    for (ll i=0;i<(ll)smallans.size();i++)
    {
        cout<<smallans[i];
        if (i!=(ll)smallans.size()-1LL)
            cout<<" ";
        else cout<<"\n";
    }
    for (ll i=0;i<(ll)bigans.size();i++)
    {
        cout<<bigans[i];
        if (i!=(ll)bigans.size()-1LL)
            cout<<" ";
        else cout<<"\n";
    }
    return 0;
}
