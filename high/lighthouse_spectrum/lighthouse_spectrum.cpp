#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <climits>
using ll=long long;
using namespace std;
string S;ll pos=0LL; ll N=0LL;
vector<vector<ll>> ship;
void build(ll pnt)
{
    if (pnt!=-1LL) {ship[pnt].push_back(pos);ship[pos].push_back(pnt);}
    int cur=S[pos]-'0'; ll org=pos; pos++;
    for (ll i=0LL;i<cur;i++) build(org);
    return;
}
vector<vector<ll>> dp;
void dfs1(ll pwd,ll pnt)
{
    dp[pwd][2LL]=1LL;
    ll sz=(ll)ship[pwd].size();
    if (pwd!=0LL) sz--;
    if (sz==1LL)
    {
        for (ll nxt:ship[pwd])
        {
            if (nxt==pnt) continue;
            dfs1(nxt,pwd);
            dp[pwd][0LL]+=max(dp[nxt][1LL],dp[nxt][2LL]);
            dp[pwd][1LL]+=max(dp[nxt][0LL],dp[nxt][2LL]);
            dp[pwd][2LL]+=max(dp[nxt][0LL],dp[nxt][1LL]);
        }
    }
    else if (sz==2LL)
    {
        array<array<ll,3LL>,2LL> tag;ll pcc=0LL;
        for (ll nxt:ship[pwd])
        {
            if (nxt==pnt) continue;
            dfs1(nxt,pwd);
            tag[pcc][0LL]=dp[nxt][0LL];
            tag[pcc][1LL]=dp[nxt][1LL];
            tag[pcc][2LL]=dp[nxt][2LL];
            pcc++;
        }
        dp[pwd][0LL]+=max(tag[0LL][1LL]+tag[1LL][2LL],tag[0LL][2LL]+tag[1LL][1LL]);
        dp[pwd][1LL]+=max(tag[0LL][0LL]+tag[1LL][2LL],tag[0LL][2LL]+tag[1LL][0LL]);
        dp[pwd][2LL]+=max(tag[0LL][0LL]+tag[1LL][1LL],tag[0LL][1LL]+tag[1LL][0LL]);
    }
    return;
}
void dfs2(ll pwd,ll pnt)
{
    dp[pwd][2LL]=1LL;
    ll sz=(ll)ship[pwd].size();
    if (pwd!=0LL) sz--;
    if (sz==1LL)
    {
        for (ll nxt:ship[pwd])
        {
            if (nxt==pnt) continue;
            dfs2(nxt,pwd);
            dp[pwd][0LL]+=min(dp[nxt][1LL],dp[nxt][2LL]);
            dp[pwd][1LL]+=min(dp[nxt][0LL],dp[nxt][2LL]);
            dp[pwd][2LL]+=min(dp[nxt][0LL],dp[nxt][1LL]);
        }
    }
    else if (sz==2LL)
    {
        array<array<ll,3LL>,2LL> tag;ll pcc=0LL;
        for (ll nxt:ship[pwd])
        {
            if (nxt==pnt) continue;
            dfs2(nxt,pwd);
            tag[pcc][0LL]=dp[nxt][0LL];
            tag[pcc][1LL]=dp[nxt][1LL];
            tag[pcc][2LL]=dp[nxt][2LL];
            pcc++;
        }
        dp[pwd][0LL]+=min(tag[0LL][1LL]+tag[1LL][2LL],tag[0LL][2LL]+tag[1LL][1LL]);
        dp[pwd][1LL]+=min(tag[0LL][0LL]+tag[1LL][2LL],tag[0LL][2LL]+tag[1LL][0LL]);
        dp[pwd][2LL]+=min(tag[0LL][0LL]+tag[1LL][1LL],tag[0LL][1LL]+tag[1LL][0LL]);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>S; for (char ch:S) N+=ch-'0';
    ship.resize(N+2LL,{}); build(-1LL);
    dp.assign(N+2LL,vector<ll> (3LL,0LL)); dfs1(0LL,-1LL);
    cout<<max({dp[0LL][0LL],dp[0LL][1LL],dp[0LL][2LL]})<<' ';
    dp.assign(N+2LL,vector<ll> (3LL,0LL)); dfs2(0LL,-1LL);
    cout<<min({dp[0LL][0LL],dp[0LL][1LL],dp[0LL][2LL]})<<'\n';
    return 0;
}
