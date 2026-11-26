#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using ll=long long;
using namespace std;
ll Q,N;
struct dat {ll P,S,T;};
vector<dat> line;
vector<ll> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cin>>Q>>N;
    line.resize(N+1LL,{-1LL,-1LL,-1LL});
    for (ll i=1LL;i<=N;i++) {ll p,s,t;cin>>p>>s>>t;line[i]={p,s,t};}
    sort(line.begin(),line.end(),[](const dat& a,const dat& b){return a.P<b.P;});
    dp.resize(N+1LL,LLONG_MAX/4LL); dp[0LL]=0LL;
    for (ll i=1LL;i<=N;i++)
    {
        ll summ=0LL,timm=0LL;
        for (ll j=i;j>0LL;j--)
        {
            if (summ+line[j].S<=Q)
            {
                summ+=line[j].S;
                timm=max(timm,line[j].T);
                dp[i]=min(dp[i],dp[j-1LL]+timm);
            }
            else break;
        }
    }
    cout<<dp[N]<<'\n'; return 0;
}
