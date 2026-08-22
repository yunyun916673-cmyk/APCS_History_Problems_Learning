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
	for (ll i=1LL;i<=n;i++) cin>>line[i];
	vector<ll> dp(k+1LL,-1e15);
	for (ll i=1LL;i<=n;i++)
	{
		vector<ll> nxt(k+1LL);
		nxt[k]=max(dp[k]+line[i],line[i]);
		ans=max(ans,nxt[k]);
		for (ll j=k-1LL;j>=0LL;j--)
		{
			nxt[j]=max(dp[j]+line[i],dp[j+1LL]);
			ans=max(ans,nxt[j]);
		}
		dp=nxt;
	}
	cout<<ans; return 0;
}