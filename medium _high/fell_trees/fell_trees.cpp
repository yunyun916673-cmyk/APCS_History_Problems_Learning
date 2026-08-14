#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,l,total=0LL,ans=0LL;
vector<ll> line,high;
vector<pair<ll,ll>> oftt;
vector<bool> fail;
queue<ll> temp;
void tryy(ll i)
{
    if (i<0LL || i>=n) return;
    auto [lf,rf]=oftt[i];
    ll lcnt=line[i]-high[i];
    ll rcnt=line[i]+high[i];
    if (lcnt>=0LL && (lf==-1 || lcnt>=line[lf])) temp.push(i);
    else if (rcnt<=l && (rf==n || rcnt<=line[rf])) temp.push(i);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin>>n>>l;
    line.resize(n); high.resize(n);
    for (ll i=0;i<n;i++) cin>>line[i];
    for (ll i=0;i<n;i++) cin>>high[i];
    oftt.resize(n); fail.assign(n,false);
    for (ll i=0;i<n;i++)
    {oftt[i]={i-1LL,i+1LL};tryy(i);}
    while (!temp.empty())
    {
        ll pos=temp.front(); temp.pop();
        if (fail[pos]) continue; fail[pos]=true;
        total++; ans=max(ans,high[pos]);
        auto [lt,rt]=oftt[pos];
        if (lt!=-1LL) oftt[lt].first=rt;
        if (rt!=n) oftt[rt].second=lt;
        tryy(lt); tryy(rt);
    }
    cout<<total<<"\n"<<ans; return 0;
}
