#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct dat {vector<int> P,U,L;int sumP,sumU,sumL;};
int k,N;
vector<dat> teams;
vector<int> paths={-1};
unordered_map<int,bool> unmap;
vector<vector<int>> vec;
void dfs()
{
    if ((int)paths.size()==2*k+2) {vec.push_back(paths);return;}
    for (int i=1;i<=2*k+1;i++)
    {
        if (unmap[i]) continue;
        unmap[i]=true; paths.push_back(i);
        dfs();
        unmap[i]=false; paths.pop_back();
    }
    return;
}
bool fight(const vector<int>& A,const vector<int>& B,const int& sA,const int& sB)
{
    for (auto& vecc:vec)
    {
        int p1=0,p2=0;
        for (int i=1;i<=2*k+1;i++)
        {
            if (A[i]>B[vecc[i]]) p1++;
            else if (A[i]<B[vecc[i]]) p2++;
            else
            {
                if (sA>sB) p1++;
                else p2++;
            }
        }
        if (p1>p2) return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>k>>N;
    teams.resize(N+1LL);
    for (int i=1;i<=N;i++)
    {
        int s; cin>>s;
        teams[s].P.resize(2*k+2);
        teams[s].U.resize(2*k+2);
        teams[s].L.resize(2*k+2);
        for (int j=1;j<=2*k+1;j++)
        {cin>>teams[s].P[j];teams[s].sumP+=teams[s].P[j];}
        for (int j=1;j<=2*k+1;j++)
        {cin>>teams[s].U[j];teams[s].sumU+=teams[s].U[j];}
        for (int j=1;j<=2*k+1;j++)
        {cin>>teams[s].L[j];teams[s].sumL+=teams[s].L[j];}
    }
    dfs();
    int S1=-1;
    for (int i=N;i>0;i--)
    {
        bool win=true;
        for (int j=1;j<=N&&win;j++)
        {
            if (i==j) continue;
            win=fight(teams[i].P,teams[j].P,teams[i].sumP,teams[j].sumP);
        }
        if (win) {S1=i;break;}
    }
    int S2=-1;
    for (int i=N;i>0;i--)
    {
        bool win=true;
        for (int j=1;j<=N&&win;j++)
        {
            if (i==j) continue;
            win=fight(teams[i].U,teams[j].L,teams[i].sumU,teams[j].sumL);
        }
        if (win) {S2=i;break;}
    }
    cout<<S1<<" "<<S2<<"\n"; return 0;
}
