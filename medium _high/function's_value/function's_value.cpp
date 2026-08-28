#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
vector<string> S;int pos=0,sz;
int F(int x) {return 2*x-3;}
int G(int x,int y) {return 2*x+y-7;}
int H(int x,int y,int z) {return 3*x-2*y+z;}
int dfs()
{
    string s=S[pos]; pos++;
    if (s=="f")
    {
        int x=dfs();
        return F(x);
    }
    if (s=="g")
    {
        int x=dfs();
        int y=dfs();
        return G(x,y);
    }
    if (s=="h")
    {
        int x=dfs();
        int y=dfs();
        int z=dfs();
        return H(x,y,z);
    }
    return stoi(s);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string org,s; getline(cin,org);
    stringstream ss(org);
    while (ss>>s) S.push_back(s);
    int sz=(int)S.size();
    cout<<dfs(); return 0;
}
