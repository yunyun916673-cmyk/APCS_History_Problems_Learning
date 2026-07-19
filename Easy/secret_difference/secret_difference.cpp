#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a=0,b=0;
    string x; cin>>x;
    for (int i=0;i<(int)x.size();i++)
    {
        if ((i+1)%2) a+=x[i]-'0';
        else b+=x[i]-'0';
    }
    cout<<abs(a-b)<<"\n";
    return 0;
}
