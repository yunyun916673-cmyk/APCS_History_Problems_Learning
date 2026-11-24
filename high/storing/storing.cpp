#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using ll=long long;
using namespace std;
ll M,S,N; vector<ll> valume;
bitset<100005> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>M>>S>>N;
    valume.resize(N+1LL,0LL);ll summ=0LL;
    for (ll i=1LL;i<=N;i++) {cin>>valume[i];summ+=valume[i];}
    ll K=M-summ; if (K>=S) {cout<<0<<'\n';return 0;}
    K=S-K; dp[0]=1;
    for (ll i=1LL;i<=N;i++) dp|=(dp<<valume[i]);
    cout<<dp._Find_next(K-1LL)<<'\n'; return 0;
}
