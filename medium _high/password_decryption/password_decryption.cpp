#include <iostream>
using ll=long long;
using namespace std;
ll n,ans=0LL;
void dfs(ll s,bool a3,bool a5,bool a7)
{
    if (s!=0LL&&s>n) return;
    if (s!=0LL&&a3&&a5&&a7) ans++;
    dfs(10LL*s+3,true,a5,a7);
    dfs(10LL*s+5,a3,true,a7);
    dfs(10LL*s+7,a3,a5,true);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>n;
    dfs(0LL,false,false,false);
    cout<<ans; return 0;
}
