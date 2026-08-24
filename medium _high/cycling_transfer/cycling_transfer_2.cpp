#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long get_ans(int n,int m)
{
    vector<long long> memo(n,0LL);
    memo[0]=1LL;
    vector<long long> nxt(n);
    for (int step=1;step<=m;step++)
    {
        fill(nxt.begin(),nxt.end(),0LL);
        for (int i=0;i<n;i++)
        {
            if (memo[i]>0LL)
            {
                int nxt1=(i+1)%n,nxt2=(i+n-1)%n;
                nxt[nxt1]+=memo[i];
                nxt[nxt2]+=memo[i];
            }
        }
        memo=nxt;
    }
    return memo[0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); int n,m;
    cin>>n>>m;
    cout<<get_ans(n,m); return 0;
}
