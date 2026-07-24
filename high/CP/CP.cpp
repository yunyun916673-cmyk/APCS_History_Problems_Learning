#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>
using namespace std;
using ll=long long;
ll m,n;
unordered_map<ll,ll> org;
int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
cin>>m>>n;
const ll tmp=(1LL<<m)-1LL;
for (ll i=0;i<n;i++)
{
string x; cin>>x;
ll tst=0;
for (char ch:x)
{
ll wh;
wh=(isupper(ch)?ch-'A':ch-'a'+26);
tst|=(1LL<<wh);
}
org[tst]++;
}
ll ans=0;
for (auto [key,value]:org)
{
ll puzz=tmp^key;
auto it=org.find(puzz);
if (it!=org.end())
ans+=value*it->second;
}
cout<<ans/2;
return 0;
}