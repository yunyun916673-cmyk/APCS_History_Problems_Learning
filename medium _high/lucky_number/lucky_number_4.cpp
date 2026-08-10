#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using ll=long long;
using namespace std;
const ll INF=1e18;
ll n,ov=0LL; vector<ll> line;
unordered_map<ll,ll> cnt;
vector<ll> Pt;
vector<vector<ll>> st;
void build()
{
    for (ll i=1;i<=n;i++) st[0][i]=line[i];
    for (ll i=1;i<ov;i++)
        for (ll j=1;j+(1LL<<i)-1LL<=n;j++)
            st[i][j]=min(st[i-1LL][j],st[i-1LL][j+(1LL<<(i-1LL))]);
    return;
}
ll query(ll L,ll R)
{
    ll ove=0LL,len=R-L+1LL;
    while ((1LL<<ove)<=len) ove++; ove--;
    return min(st[ove][L],st[ove][R-(1LL<<ove)+1LL]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n; line.resize(n+1LL); Pt.resize(n+1LL);
    for (ll i=1;i<=n;i++)
    {
        ll x; cin>>x;
        line[i]=x; cnt[x]=i; Pt[i]=x;
        if (i!=1LL) Pt[i]+=Pt[i-1LL];
    }
    while ((1LL<<ov)<=n) ov++;
    st.assign(ov,vector<ll> (n+1LL,INF));
    build();
    ll L=1LL,R=n;
    while (L<R)
    {
        ll mid=cnt[query(L,R)];
        if (Pt[mid-1LL]-Pt[L-1LL]>Pt[R]-Pt[mid]) 
        {R=mid-1LL;} else L=mid+1LL;
    }
    cout<<line[L];
    return 0;
}
