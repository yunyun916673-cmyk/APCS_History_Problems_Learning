#include <iostream>
#include <vector>
#include <queue>
using ll=long long;
using namespace std;
ll n,m;
vector<vector<ll>> ship;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    ship.resize(n);
    vector<ll> cnt(n,0LL);
    for (ll i=0;i<m;i++)
    {
        ll a,b; cin>>a>>b; a--; b--;
        ship[a].push_back(b);
        cnt[b]++;
    }
    queue<ll> temp;
    for (ll i=0;i<n;i++)
        if (!cnt[i])
            temp.push(i);
    vector<ll> path;
    while (!temp.empty())
    {
        ll pwd=temp.front();
        temp.pop();
        path.push_back(pwd);
        for (ll chd:ship[pwd])
        {
            cnt[chd]--;
            if (!cnt[chd])
                temp.push(chd);
        }
    }
    if ((ll)path.size()!=n) cout<<"NO";
    else
    {
        cout<<"YES"<<"\n";
        for (ll i=0;i<n;i++)
        {
            cout<<path[i]+1LL;
            if (i!=n-1LL)
                cout<<"\n";
        }
    }
    return 0;
}
