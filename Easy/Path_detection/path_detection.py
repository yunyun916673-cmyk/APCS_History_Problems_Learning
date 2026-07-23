import sys
input=sys.stdin.readline
n=int(input())
nowx,nowy,nowdir=0,0,0
left,right,turn=0,0,0
for _ in range(n):
	newx,newy=map(int,input().split())
	if newx==nowx:
		if newy>nowy:
			newdir=1
		else:
			newdir=3
	else:
		if newx>nowx:
			newdir=0
		else:
			newdir=2
	d=(newdir-nowdir)%4
	if d==2:
		turn+=1
	elif d==3:
		right+=1
	elif d==1:
		left+=1
	nowx,nowy,nowdir=newx,newy,newdir
print(f"{left} {right} {turn}")		