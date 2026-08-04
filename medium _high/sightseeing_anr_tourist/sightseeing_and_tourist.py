import sys
from bisect import bisect_left,bisect_right
input=sys.stdin.readline
n,m=map(int,input().split())
come=list(map(int,input().split()))
come.sort()
total=0
for _ in range(m):
	s,e=map(int,input().split())
	left=bisect_left(come,s)
	right=bisect_right(come,e)
	total+=right-left
print(total)