import sys
from collections import deque 
input=sys.stdin.readline
n=int(input().strip())
ship=[[] for _ in range(n)]
for _ in range(n-1):
    u,v,w=map(int,input().split())
    ship[u-1].append((v-1,w%2))
    ship[v-1].append((u-1,w%2))
colors=[0 for _ in range(n)]
temp=deque()
temp.append((0,-1))
while temp:
    pwd,pnt=temp.popleft()
    for nxt,val in ship[pwd]:
        if nxt!=pnt:
            colors[nxt]=colors[pwd]^val
            temp.append((nxt,pwd))
for color in colors:
    print(color)
