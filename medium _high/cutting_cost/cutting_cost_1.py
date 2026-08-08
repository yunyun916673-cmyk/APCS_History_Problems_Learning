import sys
from sortedcontainers import SortedList
from bisect import bisect_right
input=sys.stdin.readline
n,l=map(int,input().split())
cutts=[-1 for _ in range(n)]
for _ in range(n):
	x,i=map(int,input().split())
	cutts[i-1]=x
poss=SortedList()
poss.add(0)
poss.add(l-1)
total=0
for i in range(n):
	pos=cutts[i]
	right=bisect_right(poss,pos)
	left=right-1
	total+=poss[right]-poss[left]+1
poss.add(pos)
print(total)