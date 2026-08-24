#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using ll=long long;
using namespace std;
ll bfs(ll n,ll m)
{
    queue<pair<ll,ll>> temp;
    temp.push({0LL,0LL});
    vector<vector<ll>> dp(n,vector<ll> (m+1LL,0LL));
    dp[0LL][0LL]++;
    while (!temp.empty())
    {
        auto [pwd,step]=temp.front(); temp.pop();
        ll nxt1=(pwd+1LL)%n,nxt2=(pwd+n-1LL)%n;
        if (step+1LL<=m)
        {
            dp[nxt1][step+1LL]+=dp[pwd][step];
            dp[nxt2][step+1LL]+=dp[pwd][step];
            temp.push({nxt1,step+1LL});
            temp.push({nxt2,step+1LL});
        }
    }
    return dp[0LL][m];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin>>n>>m;
    cout<<bfs(n,m); return 0;
}
