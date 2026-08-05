import sys
from collections import defaultdict
from bisect import bisect_left,bisect_right
input=sys.stdin.readline
n=int(input().strip())
xiny=defaultdict(list)
yinx=defaultdict(list)
types={}
for _ in range(n):
	x,y,t=map(int,input().split())
	xiny[y].append(x)
	yinx[x].append(y)
	types[(x,y)]=t
for y in xiny:
	xiny[y].sort()
for x in yinx:
	yinx[x].sort()
nowx,nowy,nowdir=0,0,0
total=0
outal=False
while not outal:
	if nowdir==0:
		test=bisect_right(xiny[nowy],nowx)
		if test==len(xiny[nowy]):
			outal=True
			continue
		nowx,nowy=xiny[nowy][test],nowy
	elif nowdir==2:
		test=bisect_left(xiny[nowy],nowx)
		if test==0:
			outal=True
			continue
		nowx,nowy=xiny[nowy][test-1],nowy
	elif nowdir==3:
		test=bisect_right(yinx[nowx],nowy)
		if test==len(yinx[nowx]):
			outal=True
			continue
		nowx,nowy=nowx,yinx[nowx][test]
	else:
		test=bisect_left(yinx[nowx],nowy)
		if test==0:
			outal=True
			continue
		nowx,nowy=nowx,yinx[nowx][test-1]
	type=types[(nowx,nowy)]
	if type==0:
		if nowdir==0 or nowdir==2:
			nowdir=(nowdir+3)%4
		else:
			nowdir=(nowdir+1)%4
	else:
		if nowdir==0 or nowdir==2:
			nowdir=(nowdir+1)%4
		else:
			nowdir=(nowdir+3)%4
	total+=1
print(total)