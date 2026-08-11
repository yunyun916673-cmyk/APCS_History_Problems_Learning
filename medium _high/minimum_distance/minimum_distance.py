import sys
from collections import deque
input=sys.stdin.readline
def mod(x):
    return x%1000000007
n,m=map(int,input().split())
ship=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    ship[a].append(b)
    ship[b].append(a)
dp=[0 for _ in range(n+1)]
dist=[500000 for _ in range(n+1)]
temp=deque()
temp.append(1)
dp[1],dist[1],level=1,0,0
while temp:
    sz=len(temp)
    for _ in range(sz):
        pwd=temp.popleft()
        for nxt in ship[pwd]:
            if level+1<dist[nxt]:
                dist[nxt]=level+1
                dp[nxt]=mod(dp[nxt]+dp[pwd])
                temp.append(nxt)
            elif level+1==dist[nxt]:
                dp[nxt]=mod(dp[nxt]+dp[pwd])
    level+=1
print(dp[n])
