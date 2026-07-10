#include <iostream>
#include <string>
#include <algorithm>
using ll=long long;
using namespace std;
string S;
void zero()
{
    for (ll i=0;i<(ll)S.size();i+=2)
        swap(S[i],S[i+1]);    
}
void one()
{
    for (ll i=0;i<(ll)S.size();i+=2)
        if (S[i]>S[i+1])
            swap(S[i],S[i+1]);    
}
void two()
{
    string left=S.substr(0,(ll)S.size()/2);
    string right=S.substr((ll)S.size()/2);
    string test="";
    for (ll i=0;i<(ll)S.size()/2;i++)
    { test+=left[i]; test+=right[i]; }
    S=test;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k; cin>>S>>k;
    for (ll i=0;i<k;i++)
    {
        ll cnt; cin>>cnt;
        if (cnt==0) zero();
        else if(cnt==1) one();
        else two();
    }
    cout<<S;
    return 0;
}
