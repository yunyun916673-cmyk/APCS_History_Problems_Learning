#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S; cin>>S;
    int ans=0;
    map<char,int> trans=
    {
        {'I',1},{'V',5},
        {'X',10},{'L',50},
        {'C',100},{'D',500},
        {'M',1000}
    };
    int sz=(int)S.size();
    for (int i=0;i<sz;i++)
    {
        char ch=S[i];
        if (i+1<sz&&trans[ch]<trans[S[i+1]])
        {ans-=trans[ch];}
        else {ans+=trans[ch];}
    }
    cout<<ans;
    return 0;
}
