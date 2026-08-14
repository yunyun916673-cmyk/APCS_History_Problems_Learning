#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using ll=long long;
using namespace std;
const ll dr[4LL]={0LL,1LL,0LL,-1LL};
const ll dc[4LL]={1LL,0LL,-1LL,0LL};
ll h,w,sr,sc,tr,tc;
vector<vector<char>> grid;
vector<vector<ll>> memo;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>h>>w>>sr>>sc>>tr>>tc;
    sr--; sc--; tr--; tc--;
    grid.resize(h,vector<char> (w));
    for (ll i=0;i<h;i++)
        for (ll j=0;j<w;j++)
            cin>>grid[i][j];
    memo.assign(h,vector<ll> (w,1e18)); memo[sr][sc]=0LL;
    deque<pair<ll,ll>> temp; temp.push_front({sr,sc});
    while (!temp.empty())
    { ll cnt;
        auto [r,c]=temp.front(); temp.pop_front();
        for (ll i=0LL;i<4LL;i++)
        {
            ll nr=r+dr[i],nc=c+dc[i];
            if (nr<0LL || nc<0LL || nr>=h || nc>=w) continue;
            if (grid[nr][nc]=='#') continue; cnt=memo[r][c];
            if (cnt>=memo[nr][nc]) continue; 
            memo[nr][nc]=cnt;
            temp.push_front({nr,nc});
        }
        for (ll i=r-2LL;i<=r+2LL;i++)
        {
            for (ll j=c-2LL;j<=c+2LL;j++)
            {
                if (i<0LL || j<0LL || i>=h || j>=w) continue;
                if (grid[i][j]=='#') continue; cnt=memo[r][c]+1LL;
                if (cnt>=memo[i][j]) continue;
                memo[i][j]=cnt;
                temp.push_back({i,j});
            }
        }
    }
    ll ans=memo[tr][tc]; cout<<(ans==1e18?-1LL:ans); return 0;
}
