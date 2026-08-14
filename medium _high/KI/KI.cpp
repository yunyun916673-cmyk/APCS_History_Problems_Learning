#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
using ll=long long;
using namespace std;
ll n,q;
vector<ll> temp;
vector<vector<ll>> ship;
vector<ll> answer;
void skdfs()
{
    stack<tuple<ll,ll,ll>> sck;
    sck.push({1LL,-1LL,temp[1LL]});
    while (!sck.empty())
    {
        auto [pwd,pnt,val]=sck.top();
        sck.pop();
        answer[pwd]+=val;
        for (ll chd:ship[pwd])
        {
            if (chd==pnt) continue;
            sck.push({chd,pwd,temp[chd]+val});
        }
    } return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin>>n>>q;
    temp.assign(n+1LL,0LL);
    ship.resize(n+1LL);
    answer.assign(n+1LL,0LL);
    for (ll i=0;i<n-1LL;i++)
    {
        ll a,b; cin>>a>>b;
        ship[a].push_back(b);
        ship[b].push_back(a);
    }
    for (ll i=0;i<q;i++)
    {
        ll p,x; cin>>p>>x;
        temp[p]+=x;
    } skdfs();
    for (ll i=1LL;i<=n;i++)
    {
        cout<<answer[i];
        if (i!=n) cout<<" ";
    } return 0;
}
