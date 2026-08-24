#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long get_ans(int n,int m)
{
    vector<vector<long long>> memo(2,vector<long long> (n,0LL));
    memo[0][0]=1LL; int lst=0,nst=1;
    for (int step=1;step<=m;step++)
    {
        fill(memo[nst].begin(),memo[nst].end(),0LL);
        for (int i=0;i<n;i++)
        {
            if (memo[lst][i]>0LL)
            {
                int nxt1=(i+1)%n,nxt2=(i+n-1)%n;
                memo[nst][nxt1]+=memo[lst][i];
                memo[nst][nxt2]+=memo[lst][i];
            }
        }
        lst=(lst+1)%2; nst=(nst+1)%2;
    }
    return memo[lst][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); int n,m;
    cin>>n>>m;
    cout<<get_ans(n,m); return 0;
}
