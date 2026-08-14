#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using ll=long long;
using namespace std;
ll n,len;
vector<vector<ll>> grid;
const ll dr[4LL]={0LL,1LL,0LL,-1LL};
const ll dc[4LL]={1LL,0LL,-1LL,0LL};
ll check(ll ove)
{
    if (n==1LL) return 0LL;
    queue<pair<ll,ll>> temp;
    vector<vector<bool>> visited(n,vector<bool> (n,false));
    temp.push({0LL,0LL});
    visited[0LL][0LL]=true;
    ll level=0LL;
    while (!temp.empty())
    {
        ll sz=(ll)temp.size();
        for (ll i=0;i<sz;i++)
        {
            auto [r,c]=temp.front();
            temp.pop();
            for (ll i=0LL;i<4LL;i++)
            {
                ll nr=r+dr[i];
                ll nc=c+dc[i];
                if (nr<0LL || nc<0LL || nr>=n || nc>=n)
                    continue;
                if (visited[nr][nc]) continue;
                if (abs(grid[nr][nc]-grid[r][c])>ove)
                    continue;
                visited[nr][nc]=true;
                if (nr==n-1LL && nc==n-1LL) return level+1LL;
                temp.push({nr,nc});
            }
        }
        level++;
    } return -1LL;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin>>n;
    grid.resize(n,vector<ll> (n));
    for (ll i=0;i<n;i++)
        for (ll j=0;j<n;j++)
            cin>>grid[i][j];
    ll left=0LL,right=1500000LL; ll ans=right;
    while (left<=right)
    {
        ll mid=(left+right)/2LL; ll cnt=check(mid);
        if (cnt>=0LL) {right=mid-1LL; ans=mid; len=cnt;}
        else left=mid+1LL;
    }
    cout<<ans<<"\n"<<len; return 0;
}
