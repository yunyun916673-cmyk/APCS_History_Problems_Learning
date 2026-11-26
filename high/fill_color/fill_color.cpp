#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int MOD(int x) {return (x+1000000)%1000000;}
int n,m,k,t;
vector<vector<int>> lines;
vector<int> k_line={},line={};
int pos=-1;
void dfs()
{
    if ((int)line.size()==m)
    {
        lines.push_back(line);
        if (line==k_line) pos=(int)lines.size()-1;
    }
    else
    {
        for (int i=1;i<=3;i++)
        {
            if (!line.empty()&&line.back()==i) continue;
            line.push_back(i);
            dfs();
            line.pop_back();
        }
    }
    return;
}
vector<vector<bool>> ship;
bool vers(const vector<int>& a,const vector<int>& b)
{
    for (int i=0;i<m;i++) if (a[i]==b[i]) return false;
    return true;
}
void get_ship()
{
    for (int i=0;i<t;i++)
        for (int j=0;j<t;j++)
            ship[i][j]=vers(lines[i],lines[j]);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=0;i<m;i++) {int x;cin>>x;k_line.push_back(x);}
    dfs(); t=(int)lines.size();
    if (pos==-1) {cout<<0<<'\n';return 0;}
    ship.resize(t,vector<bool> (t,false));
    get_ship();
    vector<vector<int>> dp(n+1,vector<int> (t,0));
    if (k==1) dp[k][pos]=1; else for (int i=0;i<t;i++) dp[1][i]=1;
    for (int i=2;i<=n;i++)
    {
        if (i==k)
        {
            for (int p=0;p<t;p++)
                if (ship[p][pos])
                    dp[i][pos]=MOD(dp[i][pos]+dp[i-1][p]);
        }
        else
        {
            for (int s=0;s<t;s++)
                for (int p=0;p<t;p++)
                    if (ship[p][s])
                        dp[i][s]=MOD(dp[i][s]+dp[i-1][p]);
        }
    }
    int ans=0;
    for (int i=0;i<t;i++) ans=MOD(ans+dp[n][i]);
    cout<<ans<<'\n'; return 0;
}
