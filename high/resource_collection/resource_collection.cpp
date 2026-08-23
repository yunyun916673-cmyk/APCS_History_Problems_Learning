#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using ll=long long;
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,k; cin>>n>>k;
	vector<ll> line(n+1LL);
	for (ll i=1LL;i<=n;i++) cin>> line[i];
	sort(line.begin()+1LL,line.end());
	vector<ll> puzzs;
	puzzs.push_back(1e18);
	ll left=1LL,right=left+k-1LL;
	ll mid=(left+right)/2LL;
	ll cnt=0LL;
	for (ll i=left;i<=right;i++)
		cnt+=abs(line[mid]-line[i]);
	puzzs.push_back(cnt);
	while (right<n)
	{
		cnt-=abs(line[mid]-line[left]);
		left++; right++; mid++;
		cnt+=abs(line[mid]-line[right]);
		if (!(k%2LL)) cnt-=line[mid]-line[mid-1LL];
		puzzs.push_back(cnt);
	}
	ll sz=(ll)puzzs.size()-1LL;
	vector<ll> suffix(sz+1LL,1e18);
	suffix[sz]=puzzs[sz];
	for (ll i=sz-1LL;i>0LL;i--)
		suffix[i]=min(puzzs[i],suffix[i+1LL]);
	ll ans=1e18;
	for (ll i=1LL;i+k<=sz;i++)
		ans=min(ans,puzzs[i]+suffix[i+k]);
		cout<<ans; return 0;
}