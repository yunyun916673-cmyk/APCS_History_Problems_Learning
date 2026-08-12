#include <iostream>
#include <vector>
#include <stack>
using ll=long long;
using namespace std;
struct slv{ll lf,rf,lv;};
ll n,k;
vector<ll> line;
vector<ll> sum_,vals;
ll get_pos(slv base)
{
    ll left=base.lf,right=base.rf,level=base.lv;
    if (right-left<2LL || level>k) return -1LL;
    ll pos,val=1e18;
    for (ll i=left+1LL;i<right;i++)
    {
        ll a=i*(sum_[i-1LL]-sum_[left-1LL])-(vals[i-1LL]-vals[left-1LL]);
        ll b=vals[right]-vals[i]-i*(sum_[right]-sum_[i]);
        ll cnt=abs(a-b);
        if (cnt<val) {pos=i;val=cnt;}
    }
    return pos;
}
ll skdfs()
{
    ll total=0LL;
    stack<slv> stk;
    stk.push({1LL,n,1LL});
    while (!stk.empty())
    {
        auto [left,right,level]=stk.top();
        stk.pop();
        ll mid=get_pos({left,right,level});
        if (mid==-1LL) continue;
        total+=line[mid];
        stk.push({mid+1LL,right,level+1LL});
        stk.push({left,mid-1LL,level+1LL});
    }
    return total;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k; line.resize(n+1LL);
    sum_.assign(n+1LL,0LL);
    vals.assign(n+1LL,0LL);
    for (ll i=1LL;i<=n;i++)
    {
        ll x; cin>>x;
        line[i]=x;
        sum_[i]+=x+sum_[i-1LL];
        vals[i]+=i*x+vals[i-1LL];
    }
    cout<<skdfs();
    return 0;
}