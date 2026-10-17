#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
struct dat {int I,J; string Path;};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    for (int t=1;t<=T;t++)
    {
        cout<<"Case #"<<t<<": ";
        string A,B; cin>>A>>B;
        int asz=(int)A.size();
        int bsz=(int)B.size();
        A=" "+A; B=" "+B;
        vector<vector<int>> dp(asz+1,vector<int> (bsz+1,0));
        for (int i=1;i<=asz;i++)
        {
            for (int j=1;j<=bsz;j++)
            {
                if (A[i]==B[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        stack<dat> sck; sck.push({asz,bsz,""});
        set<string> Ans;
        while (!sck.empty())
        {
            auto [i,j,p]=sck.top(); sck.pop();
            if (i<=0||j<=0) {Ans.insert(p);continue;}
            else if (A[i]==B[j])
            {
                p=A[i]+p;
                sck.push({i-1,j-1,p});
            }
            else
            {
                if (dp[i-1][j]==dp[i][j]) sck.push({i-1,j,p});
                if (dp[i][j-1]==dp[i][j]) sck.push({i,j-1,p});
            }
        }
        cout<<(int)Ans.size()<<"\n";
        for (const string& ans:Ans) cout<<ans<<"\n";
    }
    return 0;
}
