#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using ll=long long;
using namespace std;
ll T(string S);
ll G(string S);
ll F(string S);
ll T(string S)
{
    ll ans=1LL;ll cnt=0LL;
    string s="";
    for (char ch:S)
    {
        if (cnt==0LL&&ch=='*')
        {ans*=G(s);s="";continue;}
        if (ch=='f') cnt++;
        else if (ch==')') cnt--;
        s+=ch;
    }
    return ans*G(s);
}
ll G(string S)
{
    ll ans=0LL;ll cnt=0LL;
    string s="";
    for (char ch:S)
    {
        if (cnt==0LL&&ch=='+')
        {ans+=F(s);s="";continue;}
        if (ch=='f') cnt++;
        else if (ch==')') cnt--;
        s+=ch;
    }
    return ans+F(s);
}
ll F(string S)
{
    bool tag=true;
    for (char ch:S) 
        if (!isdigit(ch))
        {tag=false;break;}
    if (tag) return stoll(S);
    if (S[0LL]=='f')
        S=S.substr(2LL,(ll)S.size()-3LL);
    ll bb=0LL,ss=1e18,cnt=0LL;
    string s="";
    for (char ch:S)
    {
        if (cnt==0LL&&ch==',')
        {
            ll cur=T(s);s="";
            bb=max(bb,cur);
            ss=min(ss,cur);
            continue;
        }
        if (ch=='f') cnt++;
        else if (ch==')') cnt--;
        s+=ch;
    }
    ll cur=T(s);
    bb=max(bb,cur);
    ss=min(ss,cur);
    return bb-ss;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;cin>>S;
    cout<<T(S); return 0;
}
