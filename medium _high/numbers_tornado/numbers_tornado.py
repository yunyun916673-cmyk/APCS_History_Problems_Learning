import sys
input=sys.stdin.readline
dr=[0,1,0,-1]
dc=[1,0,-1,0]
n=int(input())
nowdir=int(input())
grid=[]
for _ in range(n):
	grid.append(list(map(int,input().split())))
visited=[[False]*n for _ in range(n)]
if nowdir==0:
	sr,sc=n-1,0
elif nowdir==1:
	sr,sc=0,0
elif nowdir==2:
	sr,sc=0,n-1
else:
	sr,sc=n-1,n-1
nowdir=(nowdir+2)%4
nums=[]
nums.append(grid[sr][sc])
visited[sr][sc]=True
nowr,nowc=sr,sc
while True:
	newr=nowr+dr[nowdir]
	newc=nowc+dc[nowdir]
	if newr<0 or newc<0 or newr>=n or newc>=n or visited[newr][newc]:
		nowdir=(nowdir+3)%4
		continue
	nowr,nowc=newr,newc
	visited[nowr][nowc]=True
	nums.append(grid[nowr][nowc])
	if nowr==n//2 and nowc==n//2:
		break
ans="".join(map(str,nums[::-1]))
print(ans)