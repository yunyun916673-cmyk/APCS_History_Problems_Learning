#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using ll=long long;
using namespace std;
ll f(ll x){return 2LL*x-3LL;}
ll g(ll x,ll y){return 2LL*x+y-7LL;}
ll h(ll x,ll y,ll z){return 3LL*x-2LL*y+z;}
vector<string> line;
ll pos=0;
ll dfs()
{
	string s=line[pos]; pos++;
	if (s=="f")
		return f(dfs());
	else if (s=="g")
		return g(dfs(),dfs());
	else if (s=="h")
		return h(dfs(),dfs(),dfs());
	return stoll(s);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string org,s; getline(cin,org);
	stringstream ss(org);
	while (ss>>s)
		line.push_back(s);
	cout<<dfs();
	return 0;
}