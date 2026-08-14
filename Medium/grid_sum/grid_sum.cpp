#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int s,t,n,m,r,total=0,ans=3000;
vector<vector<int>> A,B;
void check(int sr,int sc)
{
    int cur=0,cnt=0;
    for (int i=sr;i<sr+s;i++)
    {
        for (int j=sc;j<sc+t;j++)
        {
            if (B[i][j]!=A[i-sr][j-sc])
            {cur++;cnt+=abs(A[i-sr][j-sc]-B[i][j]);}
            if (cur>r) return;
        }
    }
    total++;ans=min(ans,cnt);return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s>>t>>n>>m>>r;
    A.resize(s,vector<int> (t));
    B.resize(n,vector<int> (m));
    for (int i=0;i<s;i++)
        for (int j=0;j<t;j++)
            cin>>A[i][j];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>B[i][j];
    for (int i=0;i<=n-s;i++)
        for (int j=0;j<=m-t;j++)
            check(i,j);
    cout<<total<<"\n"<<(ans==3000?-1:ans);
    return 0;
}
