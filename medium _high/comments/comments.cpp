#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <unordered_map>
using ll=long long;
using namespace std;
string S; ll sz; ll pos=0LL; ll ans=1LL;
unordered_map<ll,vector<string>> temp;
string get_str()
{
    string s="";
    for (;pos<sz;pos++)
    {
        if (S[pos]==',') {pos++;return s;}
        s+=S[pos];
    }
    return s;
}
void dfs(ll dep)
{
    string s=get_str();
    bool tag=false;
    for (char ch:s)
        if (isdigit(ch)) 
        {tag=true;break;}
    if (tag)
    {
        ll tsz=stoll(s);
        if (tsz==0LL) return;
        ans=max(ans,dep+1LL);
        for (ll i=0LL;i<tsz;i++) dfs(dep+1LL);
        return;
    }
    temp[dep].push_back(s);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin>>S;
    sz=(ll)S.size();
    while (pos<sz) dfs(1LL);
    cout<<ans<<"\n";
    ll cur=1LL;
    while (temp.count(cur))
    {
        auto &vec=temp[cur];
        cout<<vec[0LL];
        ll tsz=(ll)vec.size();
        for (ll i=1LL;i<tsz;i++)
            cout<<" "<<vec[i];
        cout<<"\n"; cur++;
    }
    return 0;
}
