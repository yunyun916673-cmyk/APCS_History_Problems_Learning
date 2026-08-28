#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using ll=long long;
using namespace std;
vector<ll> N;
void build()
{
	bitset<1000016> B;
	for (ll i=2;i<1000016LL;i++)
	{
		if (B[i]) continue;
		N.push_back(i);
		for (ll j=2*i;j<1000016LL;j+=i)
			B[j]=1;
	}
	return;
}
 string func(ll n)
 {
 	vector<ll> cnt;
 	ll tab=n;
 	for (ll num:N)
 	{
 		if (n%num) continue;
 		ll cur=1LL,ove=1LL;
 		while (ove*num<=n&&!(n%(ove*num)))
 		{
 			ove*=num;
 			cur+=ove;
 			tab/=num;
 		}
 		cnt.push_back(cur);
 	}
 	ll ans=1LL;
 	for (ll c:cnt) ans*=c;
 	if (tab!=1) ans*=(tab+1);
 	if (ans<2*n) return "deficient";
 	else if (ans>2*n) return "abundant";
 	else return "perfect";
 }
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); ll t; cin>>t;
	build();
	for (int i=0;i<t;i++)
	{
		ll n; cin>>n;
		cout<<func(n)<<"\n";
	}
	return 0;
}