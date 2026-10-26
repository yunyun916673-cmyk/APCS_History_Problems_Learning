#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
vector<vector<char>> grid=
{
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
    {'*','.','.','.','*','.','.','.','.','.','.','.','*','*','.','.','*'},
    {'*','*','.','.','*','.','.','.','.','*','.','*','.','*','.','.','*'},
    {'*','.','.','.','.','.','.','*','.','*','*','.','*','*','.','*','*'},
    {'*','.','.','*','*','.','.','.','*','*','.','.','*','*','.','*','*'},
    {'*','*','.','.','.','.','.','*','*','.','.','*','.','*','.','.','*'},
    {'*','.','.','.','.','*','.','.','.','.','.','.','.','.','.','.','*'},
    {'*','.','.','.','.','.','*','*','*','*','.','*','.','.','.','*','*'},
    {'*','*','*','*','.','*','.','*','.','.','.','.','.','.','.','.','*'},
    {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
};
int FX,FY;
int T;
int SX,SY,EX,EY;
queue<pair<int,int>> F_temp;
const int dr[4]={1,0,-1,0};
const int dc[4]={0,1,0,-1};
void carry_out()
{
    int sz=(int)F_temp.size();
    for (int i=0;i<sz;i++)
    {
        auto [r,c]=F_temp.front(); F_temp.pop();
        for (int i=0;i<4;i++)
        {
            int nr=r+dr[i],nc=c+dc[i];
            if (nr<0||nc<0||nr>=10||nc>=17) continue;
            if (grid[nr][nc]=='*') continue;
            if (nr==EX&&nc==EY) continue;
            grid[nr][nc]='*';
            F_temp.push({nr,nc});
        }
    }
    return;
}
queue<pair<int,int>> P_temp;
vector<vector<bool>> visited(10,vector<bool> (17,false));
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>FX>>FY>>T>>SX>>SY>>EX>>EY;
    F_temp.push({FX,FY});
    for (int i=0;i<T-1;i++) carry_out();
    if (grid[SX][SY]=='*') {cout<<"Help!"<<"\n"; return 0;}
    P_temp.push({SX,SY}); visited[SX][SY]=true;
    int level=0LL;
    while (!P_temp.empty())
    {
        carry_out();
        int sz=(int)P_temp.size();
        for (int s=0;s<sz;s++)
        {
            auto [r,c]=P_temp.front(); P_temp.pop();
            for (int i=0;i<4;i++)
            {
                int nr=r+dr[i],nc=c+dc[i];
                if (nr<0||nc<0||nr>=10||nc>=17) continue;
                if (grid[nr][nc]=='*'||visited[nr][nc]) continue;
                if (nr==EX&&nc==EY)
                {cout<<level+1<<"\n"; return 0;}
                visited[nr][nc]=true;
                P_temp.push({nr,nc});
            }
        }
        level++;
    }
    cout<<"Help!"<<"\n"; return 0;
}
