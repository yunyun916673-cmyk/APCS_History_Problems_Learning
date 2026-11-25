#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using ll=long long;
using namespace std;
bool check(bitset<100005>& line,ll pos)
{
    for (ll i=0LL;i<5LL;i++)
    {
        if (!line[pos]) return false;
        pos++;
    }
    pos--;
    for (ll i=5LL;i>0LL;i--)
    {
        line[pos]=0; pos--;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    bitset<100005> line; line.set();
    vector<ll> vec(n+1LL,0LL);
    for (ll i=1LL;i<=n;i++) cin>>vec[i];
    sort(vec.begin(),vec.end());
    for (ll i=1LL;i<=n;i++)
    {
        ll pos=vec[i]-1LL;
        do
        {
            pos=line._Find_next(pos);
        }
        while (!check(line,pos));
    }
    ll cnt=0LL;
    for (ll i=1LL;i<=100000;i++)
    {
        if (!line[i]) cnt=0LL;
        else cnt++;
        if (cnt==30LL) {cout<<i+1LL<<'\n';break;}
    }
    return 0;
}
