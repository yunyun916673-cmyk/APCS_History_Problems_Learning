#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll m,n; vector<ll> line;
vector<ll> last_pos;
vector<ll> L;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>m>>n;
    line.resize(n+1LL,0LL);
    last_pos.resize(m+1LL,0LL);
    L.resize(n+1LL,0LL);
    for (ll i=1LL;i<=n;i++) cin>>line[i];
    for (ll i=1LL;i<=n;i++) {L[i]=max(L[i-1LL],last_pos[line[i]]+1LL);last_pos[line[i]]=i;}
    ll s=0LL,t=0LL,ans=0LL;
    for (ll i=1LL;i<=n;i++)
    {
        ll cnt=i-L[i]+1LL;
        if (cnt>ans) {s=L[i];ans=cnt;t=ans;}
    }
    cout<<s<<' '<<t<<'\n'; return 0;
}
