#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,n; cin>>x>>n;
    vector<int> foods(n);
    for(int i=0;i<n;i++) cin>>foods[i];
    sort(foods.begin(),foods.end());
    int right=foods.end()-upper_bound(foods.begin(),foods.end(),x);
    int left=lower_bound(foods.begin(),foods.end(),x)-foods.begin();
    if(right>left) cout<<right<<" "<<foods.back();
    else cout<<left<<" "<<foods.front();
    return 0;
}
