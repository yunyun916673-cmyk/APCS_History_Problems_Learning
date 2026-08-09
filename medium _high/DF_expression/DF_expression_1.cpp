#include <iostream>
#include <vector>
using namespace std;
string s; int n;
vector<int> blacks;
int sz;
vector<int> deep;
void get_cutts(int pos)
{
    int org=pos;
    int cnt=4;
    pos++;
    while (cnt>0 && pos<sz)
    {
        if (s[pos]!='2') cnt--;
        else cnt+=3;
        pos++;
    }
    deep[org]++;
    deep[pos]--;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s>>n;
    sz=(int)s.size();
    if (sz==1)
    {
        if (s[0]=='0') cout<<0;
        else cout<<(n*n);
        return 0;
    }
    int pos=0;
    deep.assign(sz+1,0);
    while (pos<sz)
    {
        char type=s[pos];
        if (type!='2')
        {
            if (type=='1')
                blacks.push_back(pos);
        }
        else get_cutts(pos);
        pos++;
    }
    for (int i=1;i<sz+1;i++)
        deep[i]+=deep[i-1];
    int total=0;
    for (int b:blacks)
    {
        int ove=n*n;
        for (int i=0;i<deep[b];i++)
            ove/=4;
        total+=ove;
    }
    cout<<total;
    return 0;
}
