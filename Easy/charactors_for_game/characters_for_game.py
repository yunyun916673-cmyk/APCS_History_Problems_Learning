import sys
input=sys.stdin.readline
n=int(input())
chs=[]
for _ in range(n):
	a,d=map(int,input().split())
	chs.append((a**2+d**2,a,d))
chs.sort()
print(chs[-2][1],chs[-2][2])	
	