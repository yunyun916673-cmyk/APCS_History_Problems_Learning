#include <iostream>
#include <algorithm>
using ll=long long;
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	ll w1,w2,h1,h2;
	cin>>n>>w1>>w2>>h1>>h2;
	ll a1=w1*w1,a2=w2*w2;
	ll v1=a1*h1,v2=a2*h2;
	ll nowvol=0;
	ll nowheight=0;
	ll adh=0;
	for (ll i=0;i<n;i++)
	{
		ll vol; cin>>vol;
		nowvol=min(v1+v2,nowvol+vol);
		ll newheight;
		if (nowvol==v1+v2) 
			newheight=h1+h2;
		else if (nowvol>=v1)
			newheight=h1+(nowvol-v1)/a2;
		else
			newheight=nowvol/a1;
		adh=max(adh,newheight-nowheight);
		nowheight=newheight;
	}
	cout<<adh;
	return 0;
}