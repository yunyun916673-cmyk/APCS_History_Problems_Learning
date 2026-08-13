#include <iostream>
#include <vector>
using ll=long long;
using namespace std;
struct pork { ll D,G,F; };
vector<pork> hums;
ll red=0LL,blue=0LL;
ll get_points(char ch)
{
    if (ch=='D') return 20LL;
    else if (ch=='G') return 10LL;
    else return 2LL;
}
void digg(ll a,char b,ll c)
{
    if (b=='D') hums[a].D+=c;
    else if (b=='G') hums[a].G+=c;
    else hums[a].F+=c; return;
}
void kill(ll a1,ll a2)
{
    hums[a1].D+=hums[a2].D;
    hums[a1].G+=hums[a2].G;
    hums[a1].F+=hums[a2].F;
    hums[a2]={0LL,0LL,0LL};
    return;
}
void steal(ll a,char b,ll c)
{
    ll cnt;
    if (b=='D') {hums[a].D+=c; cnt=c*get_points('D');}
    else if (b=='G') {hums[a].G+=c; cnt=c*get_points('G');}
    else {hums[a].F+=c; cnt=c*get_points('F');}
    if (a<4LL) blue-=cnt; else red-=cnt; return;
}
void putt(ll a,char b,ll c)
{
    ll cnt;
    if (b=='D') {hums[a].D-=c; cnt=c*get_points('D');}
    else if (b=='G') {hums[a].G-=c; cnt=c*get_points('G');}
    else {hums[a].F-=c; cnt=c*get_points('F');}
    if (a<4LL) red+=cnt; else blue+=cnt; return;
}
void transport(ll a,char b)
{
    ll cur;
    if (b=='D')
    {ll cnt=hums[a].D/2LL;hums[a].D=cnt;cur=cnt*get_points('D');}
    else if (b=='G')
    {ll cnt=hums[a].G/2LL;hums[a].G=cnt;cur=cnt*get_points('G');}
    else
    {ll cnt=hums[a].F/2LL;hums[a].F=cnt;cur=cnt*get_points('F');}
    if (a<4LL) red+=cur; else blue+=cur; return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin>>t; hums.assign(7LL,{0LL,0LL,0LL});
    for (ll i=0;i<t;i++)
    {
        ll typ; cin>>typ;
        if (typ==1LL)
        {
            ll a,c; char b;
            cin>>a>>b>>c;
            digg(a,b,c);
        }
        else if (typ==2LL)
        {
            ll a1,a2; cin>>a1>>a2;
            kill(a1,a2);
        }
        else if (typ==3LL)
        {
            ll a,c; char b;
            cin>>a>>b>>c;
            steal(a,b,c);
        }
        else if (typ==4LL)
        {
            ll a,c; char b; 
            cin>>a>>b>>c;
            putt(a,b,c);
        }
        else
        {
            ll a; char b;
            cin>>a>>b;
            transport(a,b);
        }
    }
    auto &a=hums[1LL],&b=hums[2LL],&c=hums[3LL];
    auto &d=hums[4LL],&e=hums[5LL],&f=hums[6LL];
    red+=(a.D+b.D+c.D)*get_points('D')/2LL;
    red+=(a.G+b.G+c.G)*get_points('G')/2LL;
    red+=(a.F+b.F+c.F)*get_points('F')/2LL;
    blue+=(d.D+e.D+f.D)*get_points('D')/2LL;
    blue+=(d.G+e.G+f.G)*get_points('G')/2LL;
    blue+=(d.F+e.F+f.F)*get_points('F')/2LL;
    cout<<red<<" "<<blue; return 0;
}
