#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using ll=long long;
using namespace std;
const ll INF=1e18;
ll n,m; vector<vector<ll>> ship;

ll tryy()
{
    ll ans=INF;
    vector<vector<ll>> temp(n);
    vector<bool> visited(n,false);
    stack<ll> sck; sck.push(0LL);
    visited[0LL]=true;
    while (!sck.empty())
    {
        ll pwd=sck.top(); sck.pop();
        temp[0LL].push_back(pwd);
        for (ll nxt:ship[pwd])
        {
            if (!visited[nxt])
            {
                visited[nxt]=true;
                sck.push(nxt);
            }
        }
    }
    if (visited[n-1LL]) return 0LL;
    sck.push(n-1LL); visited[n-1LL]=true;
    while (!sck.empty())
    {
        ll pwd=sck.top(); sck.pop();
        temp[n-1LL].push_back(pwd);
        for (ll nxt:ship[pwd])
        {
            if (!visited[nxt])
            {
                visited[nxt]=true;
                sck.push(nxt);
            }
        }
    }
    auto &start=temp[0LL],&endd=temp[n-1LL];
    sort(start.begin(),start.end());
    sort(endd.begin(),endd.end());
    ll left=0LL,right=0LL,base=INF;
    ll usz=(ll)start.size(),dsz=(ll)endd.size();
    while (left<usz && right<dsz)
    {
        ll l=start[left],r=endd[right];
        base=min(base,(l-r)*(l-r));
        if (l<r) left++; else right++;
    } ans=min(ans,base);
    for (ll i=1LL;i<n-1LL;i++)
    {
        if (visited[i]) continue;
        visited[i]=true; sck.push(i);
        while (!sck.empty())
        {
            ll pwd=sck.top(); sck.pop();
            temp[i].push_back(pwd);
            for (ll nxt:ship[pwd])
            {
                if (!visited[nxt])
                {
                    visited[nxt]=true;
                    sck.push(nxt);
                }
            }
        }
        auto &midd=temp[i];
        sort(midd.begin(),midd.end());
        left=0LL;right=0LL;ll lcur=INF,rcur=INF;
        usz=(ll)start.size();dsz=(ll)midd.size();
        while (left<usz && right<dsz)
        {
            ll l=start[left],r=midd[right];
            lcur=min(lcur,(l-r)*(l-r));
            if (l<r) left++; else right++;
        }
        left=0LL;right=0LL;usz=(ll)endd.size();
        while (left<usz && right<dsz)
        {
            ll l=endd[left],r=midd[right];
            rcur=min(rcur,(l-r)*(l-r));
            if (l<r) left++; else right++;
        }
        ans=min(ans,lcur+rcur);
    } return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);ll t; cin>>t;
    for (ll i=0LL;i<t;i++)
    { cin>>n>>m; ship.assign(n,{});
        for (ll i=0LL;i<m;i++)
        {
            ll u,v; cin>>u>>v; u--; v--;
            ship[u].push_back(v);
            ship[v].push_back(u);
        }
        cout<<tryy(); if (i!=t-1LL) cout<<"\n";
    } return 0;
}
