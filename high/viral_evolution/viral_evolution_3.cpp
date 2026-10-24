#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,m; ll root;
vector<vector<ll>> ship;
vector<ll> parents;
vector<ll> cnt;
vector<string> S;
ll get_typ(const char& ch)
{
    if (ch=='A') return 0LL;
    if (ch=='U') return 1LL;
    if (ch=='C') return 2LL;
    if (ch=='G') return 3LL;
    else return -1LL;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    ship.resize(n+1LL,{});
    parents.resize(n+1LL,-1LL);
    cnt.resize(n+1LL,0LL);
    S.resize(n+1LL,"");
    for (ll i=1LL;i<=n;i++)
    {
        ll pos,pnt;
        cin>>pos>>pnt; cin>>S[pos];
        if (pos==pnt) root=pos;
        else {ship[pnt].push_back(pos);cnt[pnt]++;}
        parents[pos]=pnt;
    }
    queue<ll> temp;
    ll ans=0LL;
    for (ll t=1LL;t<=m;t++)
    {
        auto org=cnt;
        for (ll i=1LL;i<=n;i++) if (!org[i])
        {temp.push(i);org[i]=-1LL;org[parents[i]]--;}
        vector<vector<ll>> dp(n+1LL,vector<ll> (4LL,LLONG_MAX/4LL));
        while (!temp.empty())
        {
            ll pwd=temp.front(); temp.pop();
            ll typ=get_typ(S[pwd][t-1LL]);
            if (typ==-1LL) for (ll j=0LL;j<4LL;j++) dp[pwd][j]=0LL;
            else dp[pwd][typ]=0LL;
            for (ll i=0LL;i<4LL;i++)
            {
                for (ll chd:ship[pwd])
                {
                    ll cur=LLONG_MAX/4LL;
                    for (ll j=0LL;j<4LL;j++)
                        cur=min(cur,dp[chd][j]+(i!=j));
                    dp[pwd][i]+=cur;
                }
            }
            ll pnt=parents[pwd];
            if (!org[pnt])
            {
                temp.push(pnt);
                org[pnt]=-1LL;
                org[parents[pnt]]--;
            }
        }
        ll curr=LLONG_MAX/4LL;
        for (ll i=0LL;i<4LL;i++) curr=min(curr,dp[root][i]);
        ans+=curr;
    }
    cout<<ans<<"\n"; return 0;
}
