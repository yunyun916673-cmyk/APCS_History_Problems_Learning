#include <iostream>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;
int main()
{
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 ll Na,Nb,Nc; cin>>Na>>Nb>>Nc;
 vector<ll> A(Na+1LL,0LL);
 vector<ll> B(Nb+1LL,0LL);
 vector<ll> C(Nc+1LL,0LL);
 for (ll i=1LL;i<=Na;i++) cin>>A[i];
 for (ll i=1LL;i<=Nb;i++) cin>>B[i];
 for (ll i=1LL;i<=Nc;i++) cin>>C[i];
 vector<vector<vector<ll>>> dp(Na+1LL,vector<vector<ll>> (Nb+1LL,vector<ll> (Nc+1LL,0LL)));
 for (ll i=1LL;i<=Na;i++) for (ll j=1LL;j<=Nb;j++) for (ll k=1LL;k<=Nc;k++)
 {
  if (A[i]==B[j]&&B[j]==C[k]) dp[i][j][k]=dp[i-1LL][j-1LL][k-1LL]+1LL;
  else
  {
   dp[i][j][k]=max({dp[i-1LL][j][k],dp[i][j-1LL][k],dp[i][j][k-1LL]});
  }
 }
 if (!dp[Na][Nb][Nc]) {cout<<-1<<'\n';return 0;}
 cout<<dp[Na][Nb][Nc]<<'\n';
 ll i=Na,j=Nb,k=Nc;
 vector<ll> paths={};
 while (i>0&&j>0&&k>0)
 {
  if (A[i]==B[j]&&B[j]==C[k])
  {paths.push_back(A[i]);i--;j--;k--;}
  else
  {
   if (dp[i-1LL][j][k]==dp[i][j][k]) i--;
   else if (dp[i][j-1LL][k]==dp[i][j][k]) j--;
   else k--;
  }
 }
 auto it=paths.end(); --it;
 cout<<*it<<'\n';
 while (it!=paths.begin())
 {
  --it;
  cout<<*it<<'\n';
 }
 return 0;
}
