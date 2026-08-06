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
ll get_ans()
{
    vector<vector<ll>> dp(n+1LL,vector<ll> (k+1LL,0LL));
    for (ll hum=k-1LL;hum>=0;hum--)
        for (ll pwd=n-1LL;pwd>=0;pwd--)
            dp[pwd][hum]=max(dp[pwd+1LL][hum],dp[puzzs[pwd].second+1LL][hum+1LL]+len[pwd]);
    return dp[0][0];
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
    cout<<get_ans();
    return 0;
}
