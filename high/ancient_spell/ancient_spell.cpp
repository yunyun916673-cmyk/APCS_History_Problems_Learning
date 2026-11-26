#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string A,B; getline(cin,A); getline(cin,B);
    int asz=(int)A.size();
    int bsz=(int)B.size();
    A=" "+A; B=" "+B;
    vector<vector<int>> dp(asz+1,vector<int> (bsz+1,0));
    for (int i=1;i<=asz;i++) dp[i][0]=i;
    for (int i=1;i<=bsz;i++) dp[0][i]=i;
    for (int i=1;i<=asz;i++)
    {
        for (int j=1;j<=bsz;j++)
        {
            if (A[i]==B[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
        }
    }
    cout<<dp[asz][bsz]<<'\n'; return 0;
}
