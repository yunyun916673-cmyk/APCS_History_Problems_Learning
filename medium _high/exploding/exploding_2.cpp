#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <map>
using ll=long long;
using namespace std;
const ll dr[4]={0,1,0,-1};
const ll dc[4]={1,0,-1,0};
ll m,n,q,sr,sc;
vector<vector<ll>> grid;
vector<vector<pair<ll,ll>>> cnt;
vector<pair<ll,ll>> bombs;
map<pair<ll,ll>,ll> nums;
ll bsz;
void get_cnt(ll br,ll bc,ll rad,ll pos)
{
    queue<pair<ll,ll>> spread;
    vector<vector<bool>> visited(m,vector<bool> (n,false));
    spread.push({br,bc});
    visited[br][bc]=true;
    ll level=0LL;
    while (!spread.empty())
    {
        ll sz=(ll)spread.size();
        for (ll i=0;i<sz;i++)
        {
            auto [r,c]=spread.front();
            spread.pop();
            cnt[pos].push_back({r,c});
            for (ll i=0;i<4;i++)
            {
                ll nr=r+dr[i];
                ll nc=c+dc[i];
                if (nr<0 || nc<0 || nr>=m || nc>=n)
                    continue;
                if (grid[nr][nc]==-1LL) continue;
                if (level+1LL>rad) continue;
                if (visited[nr][nc]) continue;
                visited[nr][nc]=true;
                spread.push({nr,nc});
            }
        }
        level++;
    }
    return;
}
bool check(ll rad)
{
    get_cnt(sr,sc,rad,bsz);
    vector<vector<bool>> visited(m,vector<bool> (n,false));
    queue<pair<ll,ll>> temp;
    visited[sr][sc]=true;
    temp.push({sr,sc});
    ll total=1LL;
    while (!temp.empty())
    {
        auto [r,c]=temp.front(); temp.pop();
        ll pos;
        if (r==sr && c==sc) pos=bsz;
        else pos=nums[{r,c}];
        for (auto [tr,tc]:cnt[pos])
        {
            if (visited[tr][tc]) continue;
            visited[tr][tc]=true; total++;
            if (grid[tr][tc]>0LL) temp.push({tr,tc});
        }
    }
    cnt[bsz].clear();
    return total>=q;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n>>q;
    grid.resize(m,vector<ll> (n));
    for (ll i=0;i<m;i++)
    {
        for (ll j=0;j<n;j++)
        {
            ll x; cin>>x; grid[i][j]=x;
            if (x==-2LL) {sr=i;sc=j;}
            if (x>0) bombs.push_back({i,j});
        }
    }
    bsz=(ll)bombs.size();
    cnt.resize(bsz+1LL);
    for (ll i=0;i<bsz;i++)
    {
        ll br=bombs[i].first,bc=bombs[i].second;
        nums[{br,bc}]=i;
        get_cnt(br,bc,grid[br][bc],i);
    }
    ll left=1LL,right=300000; ll ans=right;
    while (left<=right)
    {
        ll mid=(left+right)/2;
        if (check(mid)) {right=mid-1LL;ans=mid;}
        else left=mid+1LL;
    }
    cout<<ans;
    return 0;
}
