#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using ll=long long;
using namespace std;
ll T(string S);
ll G(string S);
ll F(string S);
ll F(string S)
{
    ll sz=(ll)S.size();
    if (sz==0LL) return 0LL;
    bool tag=true;
    for (ll i=0LL;i<sz;i++)
        if (!isdigit(S[i])) tag=false;
    if (tag) return stoll(S);
    S=S.substr(2LL,sz-3LL); sz-=3LL;
    ll pos=0LL;
    string s="";
    ll target=0LL;
    ll bigg=0LL,smll=1e18;
    while (pos<sz)
    {
        char ch=S[pos]; pos++;
        if (ch=='f') {target++;s+=ch;}
        else if (ch==')') {target--;s+=ch;}
        else if (ch==','&&target==0LL)
        {
            ll cur=T(s);s="";
            bigg=max(bigg,cur);
            smll=min(smll,cur);
        }
        else s+=ch;
    }
    ll cur=T(s);s="";
    bigg=max(bigg,cur);
    smll=min(smll,cur);
    return bigg-smll;
}
ll G(string S)
{
    ll sz=(ll)S.size();
    if (sz==0LL) return 1LL;
    ll pos=0LL;
    string s="";
    ll ans=0LL;
    while (pos<sz)
    {
        char ch=S[pos]; pos++;
        if (ch=='+') {ans+=F(s);s="";}
        else s+=ch;
    }
    return ans+F(s);
}
ll T(string S)
{
    ll sz=(ll)S.size();
    if (sz==0LL) return 0LL;
    ll pos=0LL;
    string s="";
    ll ans=1LL;
    while (pos<sz)
    {
        char ch=S[pos]; pos++;
        if (ch=='*') {ans*=G(s);s="";}
        else s+=ch;
    }
    return ans*G(s);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string L;cin>>L;
    cout<<T(L); return 0;
}
