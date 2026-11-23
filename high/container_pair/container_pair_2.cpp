#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
ll ans=0LL;
void dfs_merge(vector<ll>& vec,ll left,ll right)
{
    vector<ll> temp={};
    ll mid=(left+right)/2LL;
    ll i=left,j=mid+1LL;
    while (i<=mid&&j<=right)
    {
        if (vec[i]<=vec[j]) {temp.push_back(vec[i]);i++;}
        else {temp.push_back(vec[j]);j++;ans+=mid-i+1LL;}
    }
    while (i<=mid) {temp.push_back(vec[i]);i++;}
    while (j<=right) {temp.push_back(vec[j]);j++;}
    ll sz=(ll)temp.size();
    for (ll i=0LL;i<sz;i++) vec[left+i]=temp[i];
    return;
}
void dfs_sort(vector<ll>& vec,ll left,ll right)
{
    if (left>=right) return;
    ll mid=(left+right)/2LL;
    dfs_sort(vec,left,mid); dfs_sort(vec,mid+1LL,right);
    dfs_merge(vec,left,right); return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<ll> line(n);
    for (ll i=0LL;i<n;i++) cin>>line[i];
    dfs_sort(line,0LL,n-1LL);
    cout<<ans<<'\n'; return 0;
}
