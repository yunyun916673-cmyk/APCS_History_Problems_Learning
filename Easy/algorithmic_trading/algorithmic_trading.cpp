#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); int n,D,ans=0,org;
    cin>>n>>D>>org; bool havv=true;
    int bigg=org+D,smll=org-D;
    for (int i=1LL;i<n;i++)
    {
        int cur; cin>>cur;
        if (havv&&cur>=bigg)
        {
            ans+=cur-org;
            smll=cur-D;
            havv=false;
        }
        else if ((!havv)&&cur<=smll)
        {
            bigg=cur+D;
            org=cur;
            havv=true;
        }
    } cout<<ans; return 0;
}
