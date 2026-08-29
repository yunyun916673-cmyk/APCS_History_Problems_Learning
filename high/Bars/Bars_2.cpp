#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void check(const vector<int>& cnt,const int& p,const int& n)
{
    vector<bool> dp(n+1,false);
    dp[0]=true;
    for (int i=1;i<=p;i++)
        for (int j=n;j>=0;j--)
            if (dp[j]||(j>=cnt[i-1]&&dp[j-cnt[i-1]]))
                dp[j]=true;
    if (dp[n]) cout<<"YES"; else cout<<"NO";
    cout<<"\n"; return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    for (int i=0;i<t;i++)
    {
        int n,g;cin>>n>>g;
        vector<int> cnt;
        for (int i=0;i<g;i++)
        {
            int x;cin>>x;
            if (x<=n) cnt.push_back(x);
        }
        sort(cnt.begin(),cnt.end());
        check(cnt,(int)cnt.size(),n);
    }
    return 0;
}
