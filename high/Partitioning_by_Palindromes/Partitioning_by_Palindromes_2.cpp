#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void build(const string& S,vector<vector<bool>>& temp)
{
    int sz=(int)S.size();
    temp.assign(sz,vector<bool> (sz,false));
    for (int i=1;i<sz;i++)
    {
        temp[i][i]=true;
        if (i+1<sz&&S[i]==S[i+1])
            temp[i][i+1]=true;
    }
    for (int len=3;len<sz;len++)
    {
        for (int i=1;i+len-1<sz;i++)
        {
            int j=i+len-1;
            if (S[i]==S[j]&&i+1<sz&&temp[i+1][j-1])
                temp[i][j]=true;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);int t;cin>>t;
    while (t--)
    {
        string S;cin>>S;S=" "+S;
        vector<vector<bool>> temp;
        build(S,temp);
        int sz=(int)S.size();
        vector<int> dp(sz,1e9);
        dp[0]=0;
        for (int i=1;i<sz;i++)
            for (int j=1;j<=i;j++)
                if (temp[j][i])
                    dp[i]=min(dp[i],dp[j-1]+1);
        cout<<dp[sz-1]<<"\n";
    }
    return 0;
}
