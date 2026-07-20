#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,t; cin>>a>>b>>t;
    bool pass=false;
    if ((a&b)==t) {cout<<"AND"<<"\n";pass=true;}
    if ((a|b)==t) {cout<<"OR"<<"\n";pass=true;}
    if ((a^b)==t) {cout<<"XOR"<<"\n";pass=true;}
    if (!pass) cout<<"IMPOSSIBLE";
    return 0;
}
