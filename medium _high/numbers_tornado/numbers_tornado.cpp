#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<vector<int>> grid(n,vector<int> (n));
    vector<vector<bool>> visited(n,vector<bool> (n,false));
    int nowdir; cin>>nowdir;
    int sr,sc;
    if (nowdir==0) {sr=n-1;sc=0;nowdir=2;}
    else if (nowdir==1) {sr=0;sc=0;nowdir=3;}
    else if (nowdir==2) {sr=0;sc=n-1;nowdir=0;}
    else {sr=n-1; sc=n-1;nowdir=1;}
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>grid[i][j];
    vector<int> nums;
    nums.push_back(grid[sr][sc]);
    visited[sr][sc]=true;
    int nowr=sr,nowc=sc;
    while (true)
    {
        int newr=nowr,newc=nowc;
        if (nowdir==0) newc--;
        else if (nowdir==1) newr--;
        else if (nowdir==2) newc++;
        else newr++;
        if (newr<0 || newc<0 || newr>=n || 
            newc>=n || visited[newr][newc])
        {nowdir=(nowdir+3)%4;continue;}
        nowr=newr;nowc=newc;
        visited[nowr][nowc]=true;
        nums.push_back(grid[nowr][nowc]);
        if (nowr==n/2 && nowc==n/2)
            break;
    }
    reverse(nums.begin(),nums.end());
    for (int k:nums) cout<<k;
    cout<<"\n";
    return 0;
}
