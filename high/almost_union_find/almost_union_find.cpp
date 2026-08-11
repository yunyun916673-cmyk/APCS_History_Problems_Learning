#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
ll n,m,kitt;
vector<ll> room,nowplace;
vector<ll> sizz,summ;
ll find(ll x)
{
    auto &cnt=room[x];
    if (cnt==x) return x;
    return cnt=find(cnt);
}
void unite(ll p,ll q)
{
    ll rootp=find(nowplace[p]);
    ll rootq=find(nowplace[q]);
    if (rootp==rootq) return;
    auto &sp=sizz[rootp],&sq=sizz[rootq];
    auto &mp=summ[rootp],&mq=summ[rootq];
    if (sp<sq)
    {sq+=sp; mq+=mp; room[rootp]=rootq;}
    else
    {sp+=sq; mp+=mq; room[rootq]=rootp;}
    return;
}
void escape(ll p,ll q)
{
    ll rootp=find(nowplace[p]);
    ll rootq=find(nowplace[q]);
    if (rootp==rootq) return;
    sizz[rootp]--; sizz[rootq]++;
    summ[rootp]-=p; summ[rootq]+=p;
    nowplace[p]=kitt; room[kitt]=rootq;
    kitt++; return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin>>n>>m)
    {
        kitt=n+1LL;
        room.resize(n+m+5LL);
        nowplace.resize(n+1LL);
        sizz.assign(n+m+5LL,1LL);
        summ.resize(n+m+5LL);
        for (ll i=1LL;i<=n;i++)
        {room[i]=i;nowplace[i]=i;summ[i]=i;}
        for (ll i=0LL;i<m;i++)
        {
            ll type,p; cin>>type>>p;
            if (type==1LL)
            {ll q; cin>>q; unite(p,q);}
            else if (type==2LL)
            {ll q; cin>>q; escape(p,q);}
            else
            {
                ll rootp=find(nowplace[p]);
                cout<<sizz[rootp]<<" "<<summ[rootp]<<"\n";
            }
        }
    }
    return 0;
}
