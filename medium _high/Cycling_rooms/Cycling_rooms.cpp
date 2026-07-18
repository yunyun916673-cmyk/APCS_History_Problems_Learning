#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
ll n,m;
vector<ll> sum_P;
ll nowroom=0;
void doing(ll q)
{
    ll left=nowroom; 
    ll right=left+n-1LL;
    ll ans=right;
    while (left<=right)
    {
        ll mid=(left+right)/2;
        ll score=(nowroom==0?sum_P[mid]:sum_P[mid]-sum_P[nowroom-1LL]);
        if (score>=q)
        { ans=mid; right=mid-1LL; }
        else left=mid+1LL;
    }
    nowroom=(ans+1)%n;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    sum_P.resize(2*n);
    cin>>sum_P[0];
    for (ll i=1;i<n;i++) cin>>sum_P[i];
    for (ll i=n;i<2*n;i++) sum_P[i]=sum_P[i-n];
    for (ll i=1;i<2*n;i++) sum_P[i]+=sum_P[i-1];
    for (ll i=0;i<m;i++)
    {
        ll qi; cin>>qi;
        doing(qi);
    }
    cout<<nowroom;
    return 0;
}
