#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,k;
vector<ll> foods;
vector<pair<ll,ll>> puzzs;
vector<ll> len;
void get_puzz()
{
    unordered_map<ll,ll> tmp;
    ll right=0;
    for(ll left=0;left<n;left++)
    {
        while(right<n && !tmp[foods[right]])
        {
            tmp[foods[right]]++;
            right++;
        }
        puzzs.push_back({left,right-1LL});
        len.push_back(right-left);
        tmp[foods[left]]--;
    }
}
vector<vector<ll>> dp;
ll dfs(ll pwd,ll hum)
{
    if (pwd==n || hum==k)
        return 0LL;
    if (dp[pwd][hum]!=-1)
        return dp[pwd][hum];
    ll nxt=puzzs[pwd].second+1LL;
    dp[pwd][hum]=max(dfs(pwd+1LL,hum),dfs(nxt,hum+1LL)+len[pwd]);
    return dp[pwd][hum];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    foods.resize(n);
    for (ll i=0;i<n;i++)
        cin>>foods[i];
    get_puzz();
    ll sz=(ll)puzzs.size();
    dp.assign(n,vector<ll> (k+1LL,-1LL));
    cout<<dfs(0,0);
    return 0;
}
