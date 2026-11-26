//Dilworth 定理：最少遞增子序列數量=最長嚴格遞減子序列長度
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int> line(n);
    for (int i=n-1;i>=0;i--) cin>>line[i];
    vector<int> tails={};
    for (int i=0;i<n;i++)
    {
        auto it=upper_bound(tails.begin(),tails.end(),line[i]);
        if (it==tails.end()) tails.push_back(line[i]);
        else *it=line[i];
    }
    cout<<(int)tails.size()<<'\n';
    return 0;
}
