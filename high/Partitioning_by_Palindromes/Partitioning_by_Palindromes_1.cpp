#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
using unmap=unordered_map<int,vector<int>>;
void build(const string& S,unmap& temp)
{
    int sz=(int)S.size();
    for (int i=1;i<sz;i++)
    {
        string fs="",bs="";
        for (int j=i;j<sz;j++)
        {
            char ch=S[j];
            fs=fs+ch;bs=ch+bs;
            if (fs==bs) temp[j].push_back(i);
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
        unmap temp;
        build(S,temp);
        int sz=(int)S.size();
        vector<int> dp(sz,1e9);
        dp[0]=0;
        for (int i=1;i<sz;i++)
            if (temp.count(i))
                for (int j:temp[i])
                    dp[i]=min(dp[i],dp[j-1]+1);
        cout<<dp[sz-1]<<"\n";
    }
    return 0;
}
