import sys
from collections import deque
input=sys.stdin.readline
m,n,q=map(int,input().split());
grid=[]
for i in range(m):
    grid.append(list(map(int,input().split())))
    for j in range(n):
        if grid[i][j]==-2:
            sr,sc=i,j
dr=[0,1,0,-1]
dc=[1,0,-1,0]
def bfs(orgrad):
    global grid,m,n,q,sr,sc,dr,dc
    visited=[[False]*n for _ in range(m)]
    temp=deque()
    visited[sr][sc]=True
    temp.append((sr,sc))
    total=1
    while temp:
        ther,thec=temp.popleft()
        spread=deque()
        spread.append((ther,thec));
        viscell=[[False]*n for _ in range(m)]
        viscell[ther][thec]=True
        therad=grid[ther][thec] if grid[ther][thec]>0 else orgrad
        level=0
        while spread:
            sz=len(spread)
            if level+1>therad:
                break
            for _ in range(sz):
                r,c=spread.popleft()
                for i in range(4):
                    nr=r+dr[i]
                    nc=c+dc[i]
                    if nr<0 or nc<0 or nr>=m or nc>=n or grid[nr][nc]==-1:
                        continue
                    if viscell[nr][nc]:
                        continue
                    if not visited[nr][nc]:
                        visited[nr][nc]=True
                        total+=1
                        if grid[nr][nc]>0:
                            temp.append((nr,nc))
                    viscell[nr][nc]=True
                    spread.append((nr,nc))
            level+=1
    return total>=q
left,right=0,m+n-2
ans=right
while left<=right:
    mid=(left+right)//2
    if bfs(mid):
        right=mid-1
        ans=mid
    else:
        left=mid+1
print(ans)
