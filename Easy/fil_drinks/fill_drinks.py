import sys
input=sys.stdin.readline
n=int(input())
w1,w2,h1,h2=map(int,input().split())
a1,a2=w1**2,w2**2
v1,v2=a1*h1,a2*h2
nowvol,nowheight=0,0
adh=0
for i in range(n):
	vol=int(input())
	nowvol=min(nowvol+vol,v1+v2)
	if (nowvol==v1+v2):
		newheight=h1+h2
	elif (nowvol>=v1):
		newheight=h1+(nowvol-v1)//a2
	else:
		newheight=nowvol//a1
	adh=max(adh,newheight-nowheight)
	nowheight=newheight
print(adh)