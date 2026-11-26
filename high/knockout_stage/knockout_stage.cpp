#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
ll N,S,K; vector<ll> bit;
ll lowbit(ll x) {return x&(-x);}
void update(ll x,ll val) {while (x<=N) {bit[x]+=val;x+=lowbit(x);} return;}
ll query(ll x) {ll ans=0LL;while (x>0LL) {ans+=bit[x];x-=lowbit(x);} return ans;}
ll find_xth(ll x)
{
    ll cnt=0LL,pos=0LL,step=1LL;
    while (step*2LL<=N) step*=2LL;
    while (step>0LL)
    {
        if (pos+step<=N&&cnt+bit[pos+step]<x) {pos+=step;cnt+=bit[pos];}
        step/=2LL;
    }
    return pos+1LL;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>S>>K; bit.resize(N+1LL,0LL);
    for (ll i=1LL;i<=N;i++) update(i,1LL);
    vector<ll> alived(N+1LL,K); ll killed=0LL;
    ll pos=1LL;
    while (killed<N-1LL)
    {
        ll sz=(ll)query(N);
        pos=(pos+S-2LL)%sz+1LL;
        ll st=find_xth(pos); alived[st]--;
        if (!alived[st]) {update(st,-1LL); killed++;}
    }
    ll ans=0LL;
    for (ll i=1LL;i<=N&&ans==0LL;i++) if (alived[i]) ans=i;
    cout<<ans<<'\n'; return 0;
}
