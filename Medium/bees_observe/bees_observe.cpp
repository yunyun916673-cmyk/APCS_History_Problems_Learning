#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m,n,k; cin>>m>>n>>k;
    vector<vector<char>> grid(m,vector<char> (n));
    for (ll i=0;i<m;i++)
    {
        string cur;cin>>cur;
        for (ll j=0;j<n;j++)
        {
            grid[i][j]=cur[j];
        }
    }
    ll nowr=m-1,nowc=0;
    string ans="";
    for (ll i=0;i<k;i++)
    {
        ll newr=nowr,newc=nowc;
        ll step; cin>>step;
        if (step==0) newr--;
        else if (step==1) newc++;
        else if (step==2) { newr++; newc++; }
        else if (step==3) newr++;
        else if (step==4) newc--;
        else { newr--; newc--; }
        if (newr>=0 && newc>=0 && newr<m && newc<n)
        { nowr=newr; nowc=newc; }
        ans+=grid[nowr][nowc];
    }
    unordered_set<char> temp;
    for (char ch:ans) temp.insert(ch);
    cout<<ans<<endl<<(ll)temp.size();
}
