#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using pii=pair<int,int>;
int p,q,r,m;
vector<int> ports;
vector<vector<int>> ship;
vector<int> memory;
vector<int> sp;
int input(int pos) {return ports[pos];}
int AND(int a,int b) {return a&b;}
int OR(int a,int b) {return a|b;}
int XOR(int a,int b) {return a^b;}
int NOT(int a) {return !a;}
int ans=0;
pii dfs(int pwd)
{
    if (pwd<=p)
        return {ports[pwd],0};
    if (pwd>p+q)
    {return dfs(ship[pwd][0]);}
    int pos=pwd-p;
    if (memory[pos]!=-1)
        return {memory[pos],sp[pos]};
    int type=ports[pwd];
    pii a=dfs(ship[pwd][0]);
    if (type==4)
    {
        memory[pos]=NOT(a.first);
        sp[pos]=a.second+1;
    }
    else
    {
        pii b=dfs(ship[pwd][1]);
        if (type==1)
            memory[pos]=AND(a.first,b.first);
        else if (type==2)
            memory[pos]=OR(a.first,b.first);
        else
            memory[pos]=XOR(a.first,b.first);
        sp[pos]=max(a.second,b.second)+1;
    }

    return {memory[pos],sp[pos]};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>p>>q>>r>>m;
    ports.assign(p+q+r+1,-1);
    for (int i=1;i<=p+q;i++) cin>>ports[i];
    ship.resize(p+q+r+1);
    for (int i=0;i<m;i++)
    {
        int s,e; cin>>s>>e;
        ship[e].push_back(s);
    }
    memory.assign(q+1,-1);
    sp.assign(q+1,0);
    for (int i=p+q+1;i<=p+q+r;i++)
    {
        pii x=dfs(i);
        ports[i]=x.first;
        ans=max(ans,x.second);
    }
    cout<<ans<<"\n";
    for (int i=p+q+1;i<=p+q+r;i++)
    {
        cout<<ports[i];
        if (i!=p+q+r) cout<<" ";
    }
    return 0;
}
