#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using ll=long long;
using namespace std;
const ll INF=1e16;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);ll n; cin>>n;
	vector<ll> org(n);
	vector<ll> preffix(n);
	for (ll i=0LL;i<n;i++) cin>>org[i];
	preffix[0LL]=org[0LL];
	for (ll i=1LL;i<n;i++)
		preffix[i]=org[i]+preffix[i-1LL];
	vector<vector<ll>> dp(n,vector<ll> (n,INF));
	for (ll i=0;i<n;i++) dp[i][i]=0LL;
	for (ll len=2LL;len<=n;len++)
	{
		for (ll i=0LL;i<=n-len;i++)
		{
			ll j=i+len-1LL;
			for (ll k=i;k<j;k++)
			{
				ll left=preffix[k];
				if (i-1LL>=0LL) left-=preffix[i-1LL];
				ll right=preffix[j]-preffix[k];
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1LL][j]+abs(left-right));
			}
		}
	}
	cout<<dp[0LL][n-1LL]; return 0;
}