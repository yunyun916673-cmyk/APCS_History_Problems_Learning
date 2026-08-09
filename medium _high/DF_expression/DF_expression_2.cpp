#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s; int n;
int pos=0; int sz;
int dfs(int level)
{
    char type=s[pos]; pos++;
    if (type=='0') return 0;
    else if (type=='1') return level;
    level/=4;
    int sum_=0;
    for (int i=0;i<4;i++)
        sum_+=dfs(level);
    return sum_;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s>>n; sz=(int)s.size();
    cout<<dfs(n*n);
    return 0;
}
