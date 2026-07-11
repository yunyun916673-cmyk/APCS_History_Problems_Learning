#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    int nowx=0,nowy=0,nowdir=0;
    int right=0,left=0,turn=0;
    for (int i=0;i<n;i++)
    {
        int newx,newy,newdir;
        cin>>newx>>newy;
        if (nowx==newx)
        {
            if (nowy>newy) newdir=1;
            else newdir=3;
        }
        else
        {
            if (nowx>newx) newdir=2;
            else newdir=0;
        }
        if ((newdir-nowdir+4)%4==1)
            right++;
        else if ((newdir-nowdir+4)%4==3)
            left++;
        else if ((newdir-nowdir+4)%4==2)
            turn++;
        nowx=newx; nowy=newy; nowdir=newdir;
    }
    cout<<left<<" "<<right<<" "<<turn;
    return 0;
}
