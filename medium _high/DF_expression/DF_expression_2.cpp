#include <iostream>
#include <string>
using namespace std;
string S; int n,pos=0;
int dfs(int level)
{
    char ch=S[pos];pos++;
    int ans=0;
    if (ch=='2')
        for (int i=0;i<4;i++)
            ans+=dfs(level/4);
    else if (ch=='1') ans=level;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>S>>n;
    cout<<dfs(n*n); return 0;
}
