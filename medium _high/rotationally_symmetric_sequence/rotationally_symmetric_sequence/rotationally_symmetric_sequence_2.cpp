#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
using ll=long long;
vector<ll> vec={-1LL,0LL};
void build()
{
	vector<pair<string,string>> pairs=
	{
            {"0", "0"}, {"1", "1"}, {"6", "9"}, {"8", "8"}, {"9", "6"}
    };
    queue<string> temp;
    temp.push("");
    temp.push("0");
    temp.push("1");
    temp.push("8");
    while (!temp.empty())
    {
    	string str=temp.front();
    	temp.pop();
    	if ((ll)str.size()>=18) continue;
    	if (str!=""&&str[0LL]!='0') vec.push_back(stoll(str));
    	for (auto [l,r]:pairs)
    		temp.push(l+str+r);
    }
    sort(vec.begin(), vec.end());
}
ll query(ll pos) {return vec[pos]; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); build(); 
    while (true)
    {
        ll n; cin>>n; if (n==0LL) break;
        cout<<query(n)<<"\n";
    }
    return 0;
}