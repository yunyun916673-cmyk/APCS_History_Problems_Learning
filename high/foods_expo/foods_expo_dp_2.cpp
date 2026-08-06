#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,k;
vector<ll> foods;
vector<pair<ll,ll>> puzzs;
void get_puzzs()
{
    unordered_map<ll,ll> temp;
    ll left=0,right=0;
    while (left<n)
    {
        while (right<n && temp[foods[right]]==0)
        { temp[foods[right]]++; right++; }
        puzzs.push_back({left,right});
        temp[foods[left]]--;
        left++;
    }
    return;
}
ll get_ans()
{
    vector<vector<ll>> dp(n+1LL,vector<ll> (k+1LL,0LL));
    for (ll i=n-1LL;i>=0;i--)
        for (ll j=k-1LL;j>=0;j--)
            dp[i][j]=max(dp[i+1LL][j],dp[puzzs[i].second][j+1LL]+puzzs[i].second-puzzs[i].first);
    return dp[0][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    foods.resize(n);
    for (ll i=0;i<n;i++) cin>>foods[i];
    get_puzzs();
    cout<<get_ans();
    return 0;
}
