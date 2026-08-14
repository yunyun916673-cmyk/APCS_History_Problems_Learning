#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using ll=long long;
using namespace std;
const ll dr[4LL]={0LL,1LL,0LL,-1LL};
const ll dc[4LL]={1LL,0LL,-1LL,0LL};
ll h,w,sr,sc,gr,gc;
vector<vector<ll>> grid;
ll get_typ(char ch)
{
    if(ch=='.') return 0LL;
    else if (ch=='#') return 1LL;
    else if (ch=='S') return -1LL;
    else if (ch=='G') return -2LL;
    else if (ch=='o') return 2LL;
    else if (ch=='x') return 3LL;
    else return 4LL;
}
ll bfs()
{
    queue<tuple<ll,ll,ll>> temp;
    vector<vector<vector<bool>>> visited(h,vector<vector<bool>> (w,vector<bool> (2LL,false)));
    temp.push({sr,sc,0LL}); ll level=0LL;
    visited[sr][sc][0LL]=true;
    while (!temp.empty())
    {
        ll sz=(ll)temp.size();
        for (ll i=0LL;i<sz;i++)
        {
            auto [r,c,noww]=temp.front(); temp.pop();
            for (ll i=0LL;i<4LL;i++)
            {
                ll nr=r+dr[i],nc=c+dc[i];
                if (nr<0LL || nc<0LL || nr>=h || nc>=w) continue;
                ll cnt=grid[nr][nc];
                if (cnt==1LL || (noww==0LL && cnt==3LL) || (noww==1LL && cnt==2LL))
                    continue;
                if (nr==gr && nc==gc) return level+1LL;
                ll nxw=(cnt==4LL?noww^1LL:noww);
                if (visited[nr][nc][nxw]) continue;
                visited[nr][nc][nxw]=true;
                temp.push({nr,nc,nxw});
            }
        }
        level++;
    } return -1LL;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin>>h>>w;
    grid.resize(h,vector<ll> (w));
    for (ll i=0;i<h;i++)
    {
        for (ll j=0;j<w;j++)
        {
            char ch; cin>>ch;
            ll cnt=get_typ(ch);
            grid[i][j]=cnt;
            if (cnt==-1LL)
            {sr=i;sc=j;}
            else if (cnt==-2LL)
            {gr=i;gc=j;}
        }
    }
    cout<<bfs(); return 0;
}
