#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
struct player
{
    int times;
    queue<string> show;
};
int b;
vector<player> players(9);
bitset<3> tmp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i=0;i<9;i++)
    {
        cin>>players[i].times;
        for (int j=0;j<players[i].times;j++)
        {
            string t; cin>>t;
            (players[i].show).push(t);
        }
    }
    cin>>b;
    int nowhit=-1;
    int score=0;
    int outal=0;
    while (outal<b)
    {
        nowhit=(nowhit+1)%9;
        players[nowhit].times--;
        string test=players[nowhit].show.front();
        players[nowhit].show.pop();
        if (test[1]!='B' && test[1]!='R')
        {
            outal++;
            if (!(outal%3))
            {for (int i=0;i<3;i++) tmp[i]=0;}
            continue;
        }
        int thehit=(test[0]=='H'?4:test[0]-'0');
        for (int i=0;i<thehit;i++)
        {
            for (int j=2;j>=0;j--)
            {
                if (tmp[j])
                {
                    tmp[j]=0;
                    if (j!=2) tmp[j+1]=1;
                    else score++;
                }
            }
            if (i==0) tmp[0]=1;
        }
    }
    cout<<score;
    return 0;
}
