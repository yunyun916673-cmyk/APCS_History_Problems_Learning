import sys
input=sys.stdin.readline
m,n,k,nowr,nowc=map(int,input().split())
grid=[]
for _ in range(m):
	grid.append(list(map(int,input().split())))
if grid[nowr][nowc]==0:
	print(0)
	sys.exit(0)
score=grid[nowr][nowc]
grid[nowr][nowc]-=1
nowdir=1 if score%k==0 else 0
rock=1
while True:
	newr,newc=nowr,nowc
	if nowdir==0:
		newc+=1
	elif nowdir==2:
		newc-=1
	elif nowdir==1:
		newr+=1
	else:
		newr-=1
	if newr<0 or newc<0 or newr>=m or newc>=n or grid[newr][newc]==-1:
		nowdir=(nowdir+1)%4
		continue
	if grid[newr][newc]==0:
		break
	nowr,nowc=newr,newc
	score+=grid[nowr][nowc]
	rock+=1
	grid[nowr][nowc]-=1
	if score%k==0:
		nowdir=(nowdir+1)%4
print(rock)