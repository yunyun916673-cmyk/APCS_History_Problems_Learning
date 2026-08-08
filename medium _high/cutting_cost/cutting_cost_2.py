import sys
from bisect import bisect_right,insort
input=sys.stdin.readline
n,l=map(int,input().split())
cutts=[-1 for _ in range(n)]
for _ in range(n):
	x,i=map(int,input().split())
	cutts[i-1]=x
poss=[]
poss.append(0)
poss.append(l-1)
total=0
for i in range(n):
	pos=cutts[i]
	right=bisect_right(poss,pos)
	left=right-1
	total+=poss[right]-poss[left]+1
	insort(poss,pos)
print(total)