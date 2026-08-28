#include <iostream>
#include <string>
#include <cmath>
using ll=long long;
using namespace std;
ll ans=0LL,place=10LL;
void T(ll neww)
{
    ans+=abs(neww-place);
    place=neww;
    return;
}
void L(string S,ll t)
{
    ll sz=(ll)S.size();
    for (ll i=0LL;i<t;i++)
    {
        ll pos=0LL;
        ll cnt=0LL;
        string s="";
        bool tag=false;
        ll cur;
        while (pos<sz)
        {
            char ch=S[pos];pos++;
            if (!tag&&ch=='T') T(stoll(S.substr(pos,2LL)));
            if (ch=='L') cnt++;
            if (ch=='E') cnt--;
            if (cnt==1LL&&ch=='L') {tag=true;cur=(ll)(S[pos]-'0');}
            if (cnt==0LL&&ch=='E')
            {tag=false;L(s.substr(2LL,(ll)s.size()-2LL),cur);s="";}
            if (tag) s+=ch;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;cin>>S;
    L(S,1LL); cout<<ans; return 0;
}
