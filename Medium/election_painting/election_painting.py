import sys
from collections import deque
input=sys.stdin.readline
dr=[-1,0,1,0]
dc=[0,-1,0,1]
h,w,n=map(int,input().split())
grid=[]
def bfs(sr,sc,t,x):
	global h
	global w
	global grid
	visited=[]
	for _ in range(h):
		visited.append([False]*w)
	temp=deque()
	grid[sr][sc]+=x
	visited[sr][sc]=True
	level=0
	temp.append((sr,sc))
	while temp and level<t:
		sz=len(temp)
		for _ in range(sz):
			r,c=temp.popleft()
			for i in range(4):
				nr=r+dr[i]
				nc=c+dc[i]
				if nr<0 or nc<0 or nr>=h or nc>=w or visited[nr][nc]:
					continue					
				grid[nr][nc]+=x
				visited[nr][nc]=True
				temp.append((nr,nc))
		level+=1
for _ in range(h):
	grid.append([0]*w)
for _ in range(n):
	r,c,t,x=map(int,input().split())
	bfs(r,c,t,x)
for i in range(h):
	ans=" ".join(map(str,grid[i]))
	print(ans)