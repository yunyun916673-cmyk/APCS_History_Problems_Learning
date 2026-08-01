import sys
input=sys.stdin.readline
m,n,k=map(int,input().split())
grid=list(input().strip() for _ in range(m))
nowr,nowc=m-1,0
ans=""
steps=list(map(int,input().split()))
for step in steps:
	newr,newc=nowr,nowc
	if step==0:
		newr-=1
	elif step==1:
		newc+=1
	elif step==2:
		newr+=1
		newc+=1
	elif step==3:
		newr+=1
	elif step==4:
		newc-=1
	else:
		newr-=1
		newc-=1
	if m>newr>=0 and n>newc>=0:
		nowr=newr
		nowc=newc
	ans+=grid[nowr][nowc]
tmp=set(ans)
print(ans)
print(len(tmp))