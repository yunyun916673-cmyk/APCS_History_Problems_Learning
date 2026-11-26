#include <iostream>
#include <vector>
#include <array>
#include <bitset>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    int sr,sc,er,ec; cin>>sr>>sc>>er>>ec;
    int k; cin>>k; vector<int> K(k);
    for (int i=0;i<k;i++) cin>>K[i];
    array<vector<bitset<100>>,2> dp;
    int lst=0,nst=1;
    dp[lst].resize(n);dp[nst].resize(n);
    dp[lst][sr][sc]=1;
    for (int t=0;t<k;t++)
    {
        int dr=K[t]%n,dc=K[t]%m;
        fill(dp[nst].begin(),dp[nst].end(),bitset<100>(0));
        for (int i=0;i<n;i++)
        {
            dp[nst][i]|=(dp[lst][i]<<dc)|(dp[lst][i]>>(m-dc));
            dp[nst][i]|=(dp[lst][i]>>dc)|(dp[lst][i]<<(m-dc));
            dp[nst][(i+dr)%n]|=dp[lst][i];
            dp[nst][(i-dr+n)%n]|=dp[lst][i];
        }
        swap(lst,nst);
    }
    if (dp[lst][er][ec]) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n'; return 0;
}
