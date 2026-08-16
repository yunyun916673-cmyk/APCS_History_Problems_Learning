#include <iostream>
#include <vector>
#include <queue>
using ll=long long;
using namespace std;
ll n; vector<vector<ll>> ship;
queue<ll> temp;
ll get_maxx()
{
    ll cnt=0LL;
    vector<bool> visited(n,false);
    for (ll i=0LL;i<n;i++)
    {
        if (visited[i]) continue;
        visited[i]=true;temp.push(i);cnt++;
        while (!temp.empty())
        {
            ll pwd=temp.front(); temp.pop();
            for (ll nxt:ship[pwd])
            {
                if (!visited[nxt])
                {temp.push(nxt);visited[nxt]=true;}
            }
        }
    } return cnt;
}
ll get_minn()
{
    ll cnt=0LL; bool kitt=false;
    vector<bool> visited(n,false);
    for (ll i=0LL;i<n;i++)
    {
        if (visited[i]) continue;ll cur=0LL;
        visited[i]=true;temp.push(i);
        while (!temp.empty())
        {
            ll pwd=temp.front(); temp.pop();cur++;
            for (ll nxt:ship[pwd])
            {
                if (!visited[nxt])
                {temp.push(nxt);visited[nxt]=true;}
            }
        } if (cur!=2LL) cnt++; else kitt=true;
    } return (kitt?cnt+1LL:cnt);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); ll t; cin>>t;
    for (ll i=0LL;i<t;i++)
    { cin>>n; ship.assign(n,{});
        for (ll j=0LL;j<n;j++)
        {
            ll x;cin>>x; x--;
            ship[x].push_back(j);
            ship[j].push_back(x);
        }
        cout<<get_minn()<<" "<<get_maxx();
        if (i!=t-1LL) cout<<"\n";
    } return 0;
}
