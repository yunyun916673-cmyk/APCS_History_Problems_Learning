#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);int n;cin>>n;
    vector<vector<int>> ship(n+1,vector<int> (n));
    for (int i=1;i<=n;i++)
        for (int j=1;j<n;j++)
            cin>>ship[i][j];
    vector<int> noww(n+1,1);
    vector<bool> is_sleep(n+1,false);
    queue<pair<int,int>> temp;
    for (int i=1;i<=n;i++)
        temp.push({i,ship[i][1]});
    int level=0,good=0;
    while (!temp.empty())
    {
        int sz=(int)temp.size();
        for (int s=0;s<sz;s++)
        {
            auto [a,b]=temp.front();
            temp.pop();
            if (ship[a][noww[a]]!=b||ship[b][noww[b]]!=a) continue;
            if (is_sleep[a]||is_sleep[b])
            {temp.push({a,b});continue;}
            noww[a]++;noww[b]++;good++;
            is_sleep[a]=true;is_sleep[b]=true;
            if (noww[a]<n) temp.push({a,ship[a][noww[a]]});
            if (noww[b]<n) temp.push({b,ship[b][noww[b]]});
        }
        level++;
        fill(is_sleep.begin(),is_sleep.end(),false);
    }
    cout<<(good==n*(n-1)/2?level:-1); return 0;
}
