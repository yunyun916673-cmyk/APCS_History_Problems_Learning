import sys
from collections import deque
input=sys.stdin.readline
dr,dc=[0,-1,0,1],[-1,0,1,0]
n,m=map(int,input().split())
grid=[]
for i in range(n):
	grid.append(list(map(int,input().split())))
ans=[]
def bfs(sr,sc):
	global grid
	visited=[[False]*m for _ in
range(n)]
	temp=deque([(sr,sc)])
	visited[sr][sc]=True
	level=0
	total=grid[sr][sc]
	while (temp and level<grid[sr][sc]):
		sz=len(temp)
		for _ in range(sz):
			r,c=temp.popleft()
			for i in range(4):
				nr=r+dr[i]
				nc=c+dc[i]
				if nr<0 or nc<0 or nr>=n or nc>=m or visited[nr][nc]:
					continue
				total+=grid[nr][nc]
				visited[nr][nc]=True
				temp.append((nr,nc))
		level+=1
	return total
for i in range(n):
	for j in range(m):
		if bfs(i,j)%10==grid[i][j]:
			ans.append((i,j))
print(len(ans))
for r,c in ans:
	print(f"{r} {c}")