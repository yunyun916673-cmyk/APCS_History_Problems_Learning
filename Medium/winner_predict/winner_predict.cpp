#include <iostream>
#include <vector>
using namespace std;
int n,m,k; vector<long long> S,R,F;
int dfs( vector<int> &hums)
{
    vector<int> winn,loss,all;
    int sz=(int)hums.size();
    if (sz==1) return hums[0];
    if (sz%2) hums.push_back(k);
    for (int i=0;i<sz;i+=2)
    {
        int pos1=hums[i],pos2=hums[i+1];
        auto &a=S[pos1],&b=R[pos1],&c=S[pos2],&d=R[pos2];
        long long e=a*b,f=c*d;
        if (e>=f)
        {
            long long org1=a,org2=b;
            a+=f/(2LL*org2); b+=f/(2LL*org1);
            c+=c/2LL; d+=d/2LL;
            winn.push_back(pos1);
            if (F[pos2]==m-1 || pos2==k) continue; F[pos2]++;
            loss.push_back(pos2);
        }
        else
        {
            long long org1=c,org2=d;
            c+=e/(2LL*org2); d+=e/(2LL*org1);
            a+=a/2LL; b+=b/2LL;
            winn.push_back(pos2);
            if (F[pos1]==m-1) continue; F[pos1]++;
            loss.push_back(pos1);
        }
    }
    int sizz1=(int)winn.size(),sizz2=(int)loss.size();
    int sizz=sizz1+sizz2;
    all.resize(sizz);
    for (int i=0;i<sizz1;i++) all[i]=winn[i];
    for (int i=sizz1;i<sizz;i++) all[i]=loss[i-sizz1];
    return dfs(all);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin>>n>>m;
    S.resize(n); R.resize(n);
    for (int i=0;i<n;i++) cin>>S[i];
    for (int i=0;i<n;i++) cin>>R[i];
    S.push_back(0LL);R.push_back(0LL);
    k=n;
    vector<int> hums(n);
    for (int i=0;i<n;i++)
    { int x; cin>>x; hums[i]=x-1; }
    F.assign(n+1,0);
    cout<<dfs(hums)+1; return 0;
}
