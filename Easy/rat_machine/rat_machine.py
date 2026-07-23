import sys
import bisect
input=sys.stdin.readline
x,n=map(int,input().split())
foods=sorted((map(int,input().split())))
pos=bisect.bisect_left(foods,x)
if pos<n-pos:
	print(f"{n-pos} {foods[n-1]}")
else:
	print(f"{pos} {foods[0]}")
