#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    map<pair<int,int>,int> grid;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>grid[{i,j}];
    vector<pair<int,int>> ans;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            int test=0;
            for (auto &[key,val]:grid)
            {
                int r=key.first;
                int c=key.second;
                if (abs(i-r)+abs(j-c)<=grid[{i,j}])
                    test+=val;
            }
            if (test%10==grid[{i,j}])
                ans.push_back({i,j});
        }
    }
    cout<<(int)ans.size()<<endl;
    for (int i=0;i<(int)ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}
