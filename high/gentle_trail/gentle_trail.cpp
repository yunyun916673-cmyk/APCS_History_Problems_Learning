#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using ll=long long;
using namespace std;
const ll dr[4LL]={0LL,1LL,0LL,-1LL};
const ll dc[4LL]={1LL,0LL,-1LL,0LL};
ll n; vector<vector<ll>> grid;
pair<bool,ll> check(ll ove)
{
    queue<pair<ll,ll>> temp;
    temp.push({0LL,0LL});
    vector<vector<bool>> visited(n,vector<bool> (n,false));
    ll level=0LL; visited[0LL][0LL]=true;
    while (!temp.empty())
    {
        ll sz=(ll)temp.size();
        for (ll s=0LL;s<sz;s++)
        {
            auto [r,c]=temp.front(); temp.pop();
            ll cur=grid[r][c];
            for (ll i=0LL;i<4LL;i++)
            {
                ll nr=r+dr[i],nc=c+dc[i];
                if (nr<0LL || nc<0LL || nr>=n || nc>=n)
                    continue;
                if (visited[nr][nc]) continue;
                if (abs(cur-grid[nr][nc])>ove) continue;
                if (nr==n-1LL && nc==n-1LL)
                    return {true,level+1LL};
                visited[nr][nc]=true; temp.push({nr,nc});
            }
        } level++;
    } return {false,-1LL};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>n;
    grid.resize(n,vector<ll> (n));
    for (ll i=0LL;i<n;i++)
        for (ll j=0LL;j<n;j++)
            cin>>grid[i][j];
    ll left=0LL,right=1500000LL;
    ll ans=right,answer;
    while (left<=right)
    {
        ll mid=(left+right)/2LL;
        auto [can,cnt]=check(mid);
        if (can)
        {
            right=mid-1LL;ans=mid;
            answer=cnt;
        }
        else left=mid+1LL;
    }
    cout<<ans<<"\n"<<answer; return 0;
}
