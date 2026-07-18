#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int R,C,M;
vector<vector<int>> grid;
void turning()
{
    vector<vector<int>> tgrid(C,vector<int> (R));
    for (int i=0;i<R;i++)
        for (int j=0;j<C;j++)
            tgrid[C-1-j][i]=grid[i][j];
    grid=tgrid;
    swap(R,C);
}
void flipping()
{
    vector<vector<int>> tgrid(R,vector<int> (C));
    for (int i=0;i<R;i++)
        for (int j=0;j<C;j++)
            tgrid[R-1-i][j]=grid[i][j];
    grid=tgrid;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>R>>C>>M;
    grid.assign(R,vector<int> (C));
    for (int i=0;i<R;i++)
        for (int j=0;j<C;j++)
            cin>>grid[i][j];
    vector<int> doing(M);
    for (int i=0;i<M;i++) cin>>doing[i];
    reverse(doing.begin(),doing.end());
    for (int does:doing)
    {
        if (!does) turning();
        else flipping();
    }
    cout<<R<<" "<<C<<"\n";
    for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
