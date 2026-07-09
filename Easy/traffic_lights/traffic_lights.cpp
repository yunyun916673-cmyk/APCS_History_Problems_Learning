#include <iostream>
using ll=long long;
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a,b,n; cin>>a>>b>>n;
	ll ans=0;
	for (ll i=0;i<n;i++)
	{
		ll t; cin>>t;
		if (t%(a+b)>a)
			ans+=a+b-t%(a+b);
	}
	cout<<ans;
	return 0;
}