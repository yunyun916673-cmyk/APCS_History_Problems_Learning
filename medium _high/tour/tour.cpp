#include <iostream>
#include <vector>
#include <stack>
using ll=long long;
using namespace std;
ll n,m; vector<vector<ll>> ship;
ll skdfs()
{
    stack<ll> sck; ll total=0LL;
    vector<bool> visited;
    for (ll i=0;i<n;i++)
    {
        sck.push(i);
        visited.assign(n,0LL);
        while (!sck.empty())
        {
            ll pwd=sck.top(); sck.pop();
            if (visited[pwd]) continue;
            visited[pwd]=true;
            total++;
            for (ll nxt:ship[pwd])
                    sck.push(nxt);
        }
    } return total;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin>>n>>m;
    ship.resize(n);
    for (ll i=0;i<m;i++)
    {
        ll a,b; cin>>a>>b; a--; b--;
        ship[a].push_back(b);
    }
    cout<<skdfs(); return 0;
}
