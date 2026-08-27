#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using ll=long long;
using namespace std;
vector<ll> vec={-1LL,0LL};
void build()
{
	vector<string> B={"0","1","8"};
	stack<string> sck;
	sck.push("");
	for (string b:B) sck.push(b);
	while (!sck.empty())
	{
		string str=sck.top();
		sck.pop();
		ll sz=(ll)str.size();
		if (sz>=18LL) continue;
		if (str!=""||str[0LL]!='0')
			vec.push_back(stoll(str));
		for (string b:B)
			sck.push(b+str+b);
		sck.push("6"+str+"9");
		sck.push("9"+str+"6");
	}
	sort(vec.begin(),vec.end());
	return;
}
ll query(ll pos) {return vec[pos];}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); build();
	while (true)
	{
		ll n; cin>>n;
		if (n==0LL) return 0;
		cout<<query(n)<<"\n";
	}
	return 0;
}