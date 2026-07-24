import sys
input=sys.stdin.readline
r,c,m=map(int,input().split())
grid=[]
for _ in range(r):
	grid.append(list(map(int,input().split())))
actions=list(map(int,input().split()))
actions.reverse()
for a in actions:
	if a:
		grid=grid[::-1]
	else:
		grid=[list(x) for x in zip(*grid)][::-1]
		r,c=c,r
print(r,c)
for x in grid:
	print(*x)