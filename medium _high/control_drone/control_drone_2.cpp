#include <iostream>
#include <string>
#include <cmath>
using ll=long long;
using namespace std;
string S;ll pos=0LL;
ll sz;
struct pork
{
    bool NONE;
    ll F,T,V;
};
pork L()
{
    pork cnt={true,-1LL,-1LL,0LL};
    while (pos<sz)
    {
        char ch=S[pos]; pos++;
        if (ch=='T')
        {
            ll cur=stoll(S.substr(pos,2LL)); pos+=2LL;
            if (cnt.NONE) cnt={false,cur,cur,0LL};
            else {cnt.V+=abs(cnt.T-cur);cnt.T=cur;}
        }
        else if (ch=='L')
        {
            ll t=S[pos]-'0'; pos++;
            pork rev=L();
            if (rev.NONE) continue;
            ll val=t*rev.V+(t-1LL)*abs(rev.F-rev.T);
            if (cnt.NONE) cnt={false,rev.F,rev.T,val};
            else 
            {
                cnt.V+=abs(cnt.T-rev.F)+val;
                cnt.T=rev.T;
            }
        }
        else break;
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>S;
    sz=(ll)S.size();
    pork P=L();ll ans=0LL;
    if (!P.NONE) ans=abs(10LL-P.F)+P.V;
    cout<<ans; return 0;
}
