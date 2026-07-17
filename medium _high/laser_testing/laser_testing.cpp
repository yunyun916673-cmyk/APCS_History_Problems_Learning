#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
using ll=long long;
using namespace std;
ll n;
unordered_map<ll,multiset<ll>> rowsincols,colsinrows;
map<pair<ll,ll>,ll> types;
ll nowr=0,nowc=0,nowdir=0;
ll turn=0;
void shoot()
{
    bool outal=false;
    while (!outal)
    {
        if (nowdir==0)
        {
            auto it=rowsincols[nowc].upper_bound(nowr);
            if (it==rowsincols[nowc].end())
            {
                outal=true;
                continue;
            }
            nowr=*it;
            ll type=types[{nowr,nowc}];
            if (type==0) nowdir=3;
            else nowdir=1;
            turn++;
        }
        else if (nowdir==2)
        {
            auto it=rowsincols[nowc].lower_bound(nowr);
            if (it==rowsincols[nowc].begin())
            {
                outal=true;
                continue;
            }
            --it;
            nowr=*it;
            ll type=types[{nowr,nowc}];
            if (type==0) nowdir=1;
            else nowdir=3;
            turn++;
        }
        else if (nowdir==3)
        {
            auto it=colsinrows[nowr].upper_bound(nowc);
            if (it==colsinrows[nowr].end())
            {
                outal=true;
                continue;
            }
            nowc=*it;
            ll type=types[{nowr,nowc}];
            if (type==0) nowdir=0;
            else nowdir=2;
            turn++;
        }
        else
        {
            auto it=colsinrows[nowr].lower_bound(nowc);
            if (it==colsinrows[nowr].begin())
            {
                outal=true;
                continue;
            }
            --it;
            nowc=*it;
            ll type=types[{nowr,nowc}];
            if (type==0) nowdir=2;
            else nowdir=0;
            turn++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for (ll i=0;i<n;i++)
    {
        ll x,y,t; cin>>x>>y>>t;
        rowsincols[y].insert(x);
        colsinrows[x].insert(y);
        types[{x,y}]=t;
    }
    shoot();
    cout<<turn;
    return 0;
}
