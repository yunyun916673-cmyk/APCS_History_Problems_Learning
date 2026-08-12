#include <iostream>
#include <vector>
using ll=long long;
using namespace std;

struct pork { ll pos,oldd; };

ll n,m,p,k;
vector<ll> hums;

void get_hums(ll a,ll b)
{
    if (hums[a]==a && hums[b]==b)
    {hums[a]=-1LL;hums[b]=-2LL;}
    else if (hums[a]==a && hums[b]<0LL)
        hums[a]=hums[b]%2LL-1LL;
    else if (hums[a]<0LL && hums[b]==b)
        hums[b]=hums[a]%2LL-1LL;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    hums.resize(n);

    for (ll i=0;i<n;i++) hums[i]=i;

    for (ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        get_hums(a,b);
    }

    cin>>p>>k;
    ll fir=0LL;

    vector<pair<pork,pork>> wait(k);

    for (ll i=0;i<p;i++)
    {
        bool resett=false;
        ll cnt=0LL;

        for (;cnt<k;cnt++)
        {
            ll a,b;
            cin>>a>>b;

            if (hums[a]==hums[b])
            {
                if (fir) cout<<"\n";
                else fir=1LL;

                cout<<i+1LL;
                resett=true;
                break;
            }

            auto &www=wait[cnt];

            www.first.pos=a;
            www.second.pos=b;

            www.first.oldd=hums[a];
            www.second.oldd=hums[b];

            get_hums(a,b);
        }

        cnt--;

        if (resett)
        {
            for (;cnt>=0;cnt--)
            {
                auto &www=wait[cnt];

                hums[www.first.pos]=www.first.oldd;
                hums[www.second.pos]=www.second.oldd;
            }
        }
    }

    return 0;
}