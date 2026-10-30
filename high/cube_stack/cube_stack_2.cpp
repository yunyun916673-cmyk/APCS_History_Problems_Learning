#include <iostream>
#include <bitset>
#include <algorithm>
using ll=long long;
using namespace std;
bitset<1000000> line;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while (t--)
    {
        int n,h; cin>>n>>h;
        line.reset();
        line[0]=1;
        for (int i=1;i<=n;i++)
        {
            int x,y,z; cin>>x>>y>>z;
            line=(line<<x)|(line<<y)|(line<<z);
        }
        for (int i=h;i>=0;i--)
        {
            if (line[i]) {cout<<i<<'\n';break;}
            else if (i==0) cout<<"no solution"<<'\n';
        }
    }
    return 0;
}
