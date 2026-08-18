#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using ll=long long;
using namespace std;
ll m; vector<string> cola;
unordered_set<string> popcorn;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin>>m;
    cola.resize(m); ll ans=0LL;
    for (ll i=0LL;i<m;i++)
    {string s;cin>>s;cola[i]=s;popcorn.insert(s);}
    for (ll i=0LL;i<m;i++)
    {
        auto &org=cola[i];
        ll sz=(ll)org.size();
        for (ll j=1LL;j<sz/2LL+1LL;j++)
        {
            string a=org.substr(0LL,j);
            string c=org.substr(sz-j,j);
            if (a!=c) continue;
            string b=org.substr(j,sz-2*j);
            if (popcorn.count(b)) ans++;
        }
    } cout<<ans; return 0;
}
