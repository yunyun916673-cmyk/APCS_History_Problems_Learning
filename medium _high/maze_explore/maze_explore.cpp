#include <iostream>
#include <vector>
#include <cmath>
using ll=long long;
using namespace std;
vector<ll> line;
ll ans=0LL,pos=0LL;
void dfs(ll pnt)
{
    ll cur=line[pos];pos++;
    if (cur==0LL) return;
    if (pnt!=-1LL)
        ans+=abs(pnt-cur);
    if (cur%2LL)
    {dfs(cur);dfs(cur);dfs(cur);}
    else {dfs(cur);dfs(cur);}
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);ll n;
    while (cin>>n)
        line.push_back(n);
    dfs(-1LL);
    cout<<ans; return 0;
}
