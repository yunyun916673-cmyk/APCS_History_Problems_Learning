import sys
input=sys.stdin.readline
dr=[0,-1,0,1]
dc=[-1,0,1,0]
n,m=map(int,input().split())
r,c=0,0
grid=[]
for _ in range(n):
	grid.append(list(map(int,input().split())))
for i in range(n):
	for j in range(m):
		if grid[i][j]<grid[r][c]:
			r,c=i,j
total=0
visited=[[False]*m for _ in range(n)]
while True:
	total+=grid[r][c]
	visited[r][c]=True
	nr,nc=-1,-1
	for i in range(4):
		tr=r+dr[i]
		tc=c+dc[i]
		if tr<0 or tc<0 or tr>=n or tc>=m:
			continue
		if visited[tr][tc]:
			continue
		if nr==-1 or grid[tr][tc]<grid[nr][nc]:
			nr,nc=tr,tc
	if nr==-1:
		break;
	r,c=nr,nc
print(total)