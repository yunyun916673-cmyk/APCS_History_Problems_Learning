#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
ll n,m,k;
vector<ll> gamer;
ll lowbit(ll x) {return x&(-x);}
void update(ll x,ll val)
{
    while (x<=n)
    {
        gamer[x]+=val;
        x+=lowbit(x);
    }
}
ll find_xth(ll x)
{
    ll pos=0;
    ll jump=1;
    while (2*jump<=n) {jump*=2;}
    while (jump)
    {
        if (pos+jump<=n && gamer[pos+jump]<x)
        {
            pos+=jump;
            x-=gamer[pos];
        }
        jump/=2;
    }
    return pos+1LL;
}
ll query(ll x)
{
    ll ans=0;
    while (x>0)
    {
        ans+=gamer[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    gamer.resize(n+1LL);
    for (ll i=1;i<=n;i++) update(i,1);
    ll now=1;
    for (ll i=0;i<k;i++)
    {
        ll sz=query(n);
        now=(now+m-2LL)%sz+1LL;
        ll pos=find_xth(now);
        update(pos,-1);
        sz--;
        if (now>sz) now=1;
    }
    cout<<find_xth(now)<<"\n";
}
