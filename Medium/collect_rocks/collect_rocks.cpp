#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m,n,k,nowr,nowc; cin>>m>>n>>k>>nowr>>nowc;
    vector<vector<ll>> grid(m,vector<ll> (n));
    for (ll i=0;i<m;i++)
        for (ll j=0;j<n;j++)
            cin>>grid[i][j];
    if (!grid[nowr][nowc])
    { cout<<0; return 0; }
    ll score=grid[nowr][nowc];
    ll rock=1;
    grid[nowr][nowc]--;
    ll nowdir=0;
    while (true)
    {
        ll newr=nowr,newc=nowc;
        if (nowdir==0) newc++;
        else if (nowdir==1) newr++;
        else if (nowdir==2) newc--;
        else newr--;
        if (newr<0 || newc<0 || newr>=m || newc>=n || grid[newr][newc]==-1)
        {
            nowdir=(nowdir+1)%4;
            continue;
        }
        nowr=newr; nowc=newc;
        if (!grid[nowr][nowc]) break;
        score+=grid[nowr][nowc];
        grid[nowr][nowc]--;
        rock++;
        if (!(score%k)) nowdir=(nowdir+1)%4;
    }
    cout<<rock;
    return 0;
}
