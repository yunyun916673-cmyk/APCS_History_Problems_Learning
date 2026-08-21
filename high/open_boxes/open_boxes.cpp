#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
using ll=long long;
using namespace std;
unordered_set<ll> keys;//我有哪些key
unordered_map<ll,vector<ll>> can_open;//key i 可以開誰
vector<vector<ll>> gifts;//box i 打開後得到那些key
unordered_map<ll,ll> cnt;//box i 還需多少key才能開
queue<ll> temp;//有哪些box可以開
ll n,m,k,t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k>>t;
    for (ll i=0;i<t;i++)
    {ll x; cin>>x; keys.insert(x);}
    for (ll i=0;i<n;i++)
    {
        cnt[i]=k;
        for (ll j=0;j<k;j++)
        {
            ll key; cin>>key;
            can_open[key].push_back(i);
            if (keys.count(key)) cnt[i]--;
        }
        if (cnt[i]==0LL)
        {temp.push(i); cnt[i]=-1LL;}
    }
    gifts.resize(n,vector<ll> (k));
    for (ll i=0;i<n;i++)
        for (ll j=0;j<k;j++)
            cin>>gifts[i][j];
    ll total=0LL;
    while (!temp.empty())
    {
        ll box=temp.front(); temp.pop();
        total++;
        for (ll gift:gifts[box])
        {
            if (keys.count(gift)) continue;
            keys.insert(gift);
            for (ll b:can_open[gift])
            {
                cnt[b]--;
                if (cnt[b]==0LL)
                {temp.push(b); cnt[b]=-1LL;}
            }
        }
    }
    cout<<total;
    return 0;
}
