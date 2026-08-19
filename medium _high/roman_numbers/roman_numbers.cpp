#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S; cin>>S;
    int sz=(int)S.size();
    int pos=0; string ans="";
    int base=0;
    bool tag=false;
    while (pos<sz)
    {
        char ch=S[pos]; pos++;
        if (ch=='I')
        {
            if (pos>=sz||S[pos]=='I') {base++;}
            else {tag=true;}
        }
        else if (ch=='M')
        {
            if (tag) {ans+='9';tag=false;}
            else ans+='1';
        }
        else if (ch=='D')
        {
            if (tag) {ans+='4';tag=false;}
            else ans+='5';
        }
        else if (ch=='C')
        {
            if (tag) {ans+='9';tag=false;}
            else ans+='1';
        }
        else if (ch=='L')
        {
            if (tag) {ans+='4';tag=false;}
            else ans+='5';
        }
        else if (ch=='X')
        {
            if (tag) {ans+='9';tag=false;}
            else ans+='1';
        }
        else
        {
            if (tag) {ans+='4';tag=false;}
            else ans+='5';
        }
    }
    ans+=to_string(base);
    cout<<stoi(ans);
    return 0;
}
