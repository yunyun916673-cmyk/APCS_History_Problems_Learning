#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
using ll = long long;
using namespace std;
string U, S;
ll L;
set<string> all;
unordered_set<string> every;
void dfs(string cur)
{
    if ((ll)cur.size() == L)
    {
        all.insert(cur);
        return;
    }
    for (char ch : U) dfs(cur + ch);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> U >> L >> S;
    dfs("");
    for (ll i = 0; i + L <= (ll)S.size(); i++)
        every.insert(S.substr(i, L));
    for (string test : all)
    {
        if (!every.count(test))
        {
            cout << test;
            return 0;
        }
    }
    return 0;
}
