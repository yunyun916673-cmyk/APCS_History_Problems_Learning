#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); ll ans=0LL;
	ll n,k; cin>>n>>k;
	vector<ll> line(n+1LL);
	vector<vector<ll>> dp(n+1,vector<ll> (k+1,-1e15));
	for (ll i=1LL;i<=n;i++) cin>>line[i];
	for (ll i=1LL;i<=n;i++)
	{
		dp[i][k]=max(dp[i-1LL][k]+line[i],line[i]);
		ans=max(ans,dp[i][k]);
		for (ll j=k-1LL;j>=0LL;j--)
		{
			dp[i][j]=max(dp[i-1LL][j]+line[i],dp[i-1LL][j+1LL]);
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans; return 0;
}