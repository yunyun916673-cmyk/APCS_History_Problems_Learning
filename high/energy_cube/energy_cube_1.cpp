#include <iostream>
#include<vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,m,lim; vector<ll> line;
vector<ll> preffix;
vector<vector<ll>> dp;
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
	dp.assign(2LL,vector<ll> (m+1LL,0LL));
	ll lst=0LL,nst=1LL;
	dp[lst][0LL]=1LL;
	for (ll i=1LL;i<=n;i++)
	{
		fill(dp[nst].begin(),dp[nst].end(),0LL);
		ll limt=min(preffix[i],m);
		for (ll j=0LL;j<=limt;j++)
		{
			for (ll k=0LL;k<=line[i];k++)
			{
				if (j-k<0LL) break;
				dp[nst][j]=MOD(dp[nst][j]+dp[lst][j-k]);
			}
		}
		swap(nst,lst);
	}
	cout<<dp[lst][m]; return 0;
}