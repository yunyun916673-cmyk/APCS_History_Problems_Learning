#include <iostream>
#include<vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,m,lim; vector<ll> line;
vector<ll> preffix;
vector<ll> dp;
ll MOD(ll x) {return (x+1000007)%1000007;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cin>>n>>m;
	line.resize(n+1LL);
	for (ll i=1LL;i<=n;i++) cin>>line[i];
	preffix.assign(n+1LL,0LL);
	for (ll i=1LL;i<=n;i++)
		preffix[i]=preffix[i-1LL]+line[i];
	dp.assign(m+1LL,0LL);
	dp[0LL]=1LL;
	for (ll i=1LL;i<=n;i++)
	{
		ll limt=min(preffix[i],m);
		for (ll j=limt;j>=0LL;j--)
		{
			for (ll k=1LL;k<=line[i];k++)
			{
				if (j-k<0LL) break;
				dp[j]=MOD(dp[j]+dp[j-k]);
			}
		}
	}
	cout<<dp[m]; return 0;
}