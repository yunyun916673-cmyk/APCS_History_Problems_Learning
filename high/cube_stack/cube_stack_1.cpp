#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct dat {int X,Y,Z;};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    while (T--)
    {
        int N,H; cin>>N>>H;
        vector<dat> temp(N+1,{0,0,0});
        int test=0;
        for (int i=1;i<=N;i++)
        {
            cin>>temp[i].X>>temp[i].Y>>temp[i].Z;
            test+=min({temp[i].X,temp[i].Y,temp[i].Z});
        }
        if (test>H) {cout<<"no solution"<<'\n';continue;}
        vector<vector<bool>> dp(N+1,vector<bool> (H+1,false));
        dp[0][0]=true;
        for (int i=1;i<=N;i++)
        {
            for (int j=1;j<=H;j++)
            {
                if ((j>=temp[i].X&&dp[i-1][j-temp[i].X])||
                    (j>=temp[i].Y&&dp[i-1][j-temp[i].Y])||
                    (j>=temp[i].Z&&dp[i-1][j-temp[i].Z]))
                    dp[i][j]=true;
            }
        }
        int ans=0;
        for (int i=1;i<=H;i++) if (dp[N][i]) ans=i;
        if (ans) cout<<ans<<'\n';
        else cout<<"no solution"<<'\n';
    }
    return 0;
}
