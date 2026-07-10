#include <iostream>
#include <vector>
#include <cmath>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll h,w,n; cin>>h>>w>>n;
    vector<vector<ll>> grid(h,vector<ll> (w,0));
    for (ll i=0;i<n;i++)
    {
        ll r,c,t,x; cin>>r>>c>>t>>x;
        for (ll j=0;j<h;j++)
            for (ll k=0;k<w;k++)
                if (abs(r-j)+abs(c-k)<=t)
                    grid[j][k]+=x;
    }
    for (ll i=0;i<h;i++)
    {
        for (ll j=0;j<w;j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
