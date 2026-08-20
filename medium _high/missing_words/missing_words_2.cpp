#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using ll=long long;
using namespace std;
ll L; string S,K;
unordered_set<string> lines;
void get_lines()
{
    ll sz=(ll)S.size();
    for (ll i=0LL;i+L<=sz;i++)
    {
        string s=S.substr(i,L);
        lines.insert(s);
    }
    return;
}
void dfs(string s)
{
    if ((ll)s.size()==L)
    {
        if (!lines.count(s))
        {cout<<s;exit(0);}
        return;
    }
    for (char ch:K) dfs(s+ch);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>K>>L>>S;
    get_lines();
    dfs("");
    return 0;
}
