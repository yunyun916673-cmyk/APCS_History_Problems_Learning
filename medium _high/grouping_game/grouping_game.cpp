#include <iostream>
#include <vector>
#include <stack>
using ll=long long;
using namespace std;
const ll INF=100000005;
ll n,k; vector<vector<ll>> grid;
stack<ll> sck; vector<bool> visited;
bool check(ll ove)
{ visited.assign(n,false); ll cnt=0LL;
    for (ll i=0LL;i<n;i++)
    { if (visited[i]) continue;
        visited[i]=true; cnt++; sck.push(i);
        while (!sck.empty())
        {
            ll pwd=sck.top(); sck.pop();
            for (ll nxt=0LL;nxt<n;nxt++)
            {
                if ((!visited[nxt])&&grid[pwd][nxt]<ove)
                {visited[nxt]=true;sck.push(nxt);}
            }
        }
    } if (cnt<k) return false; return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>n>>k;
    grid.resize(n,vector<ll> (n));
    for (ll i=0LL;i<n;i++)
        for (ll j=0LL;j<n;j++)
            cin>>grid[i][j];
    ll left=0LL,right=INF; ll ans=right;
    while (left<=right)
    {
        ll mid=(left+right)/2LL;
        if (check(mid)) {left=mid+1LL;ans=mid;}
        else right=mid-1LL;
    } cout<<ans; return 0;
}
