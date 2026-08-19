#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
ll n,m;ll ans=-1e18;
void gett(vector<ll> &A,vector<ll> &B)
{
    vector<vector<ll>> AB(n,vector<ll> (m));
    for (ll i=0LL;i<n;i++)
        for (ll j=0LL;j<m;j++)
            AB[i][j]=A[i]*B[j];
    ll i=0LL,j=m-1LL;
    while (j>=0LL)
    {
        ll cur=-1e18;
        ll a=i,b=j;
        while (a<n&&b<m)
        {
            cur=max(AB[a][b],cur+AB[a][b]);
            ans=max(ans,cur); a++; b++;
        } j--;
    }
    i=n-1LL; j=0LL;
    while (i>=0LL)
    {
        ll cur=-1e18;
        ll a=i,b=j;
        while (a<n&&b<m)
        {
            cur=max(AB[a][b],cur+AB[a][b]);
            ans=max(ans,cur); a++; b++;
        } i--;
    }
    i=0LL; j=0LL;
    while (i<n)
    {
        ll cur=-1e18;
        ll a=i,b=j;
        while (a>=0LL&&b<m)
        {
            cur=max(AB[a][b],cur+AB[a][b]);
            ans=max(ans,cur); a--; b++;
        } i++;
    }
    i=n-1LL; j=m-1LL;
    while (i>=0LL)
    {
        ll cur=-1e18;
        ll a=i,b=j;
        while (a<n&&b>=0LL)
        {
            cur=max(AB[a][b],cur+AB[a][b]);
            ans=max(ans,cur); a++; b--;
        } i--;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>n>>m;
    vector<ll> A(n),B(m);
    for (ll i=0LL;i<n;i++) cin>>A[i];
    for (ll i=0LL;i<m;i++) cin>>B[i];
    gett(A,B);
    reverse(A.begin(),A.end());
    gett(A,B);
    cout<<ans; return 0;
}
