import sys
from collections import deque
input=sys.stdin.readline
n,m=map(int,input().split())
ship=[[] for _ in range(n)]
temp=deque()
cnt=[0 for _ in range(n)]
for _ in range(m):
	u,v=map(int,input().split())
	ship[u-1].append(v-1)
	cnt[v-1]+=1
for i in range(n):
	if cnt[i]==0:
		temp.append(i)
path=[]
while temp:
	pwd=temp.popleft()
	path.append(pwd+1)
	for nxt in ship[pwd]:
		cnt[nxt]-=1
		if cnt[nxt]==0:
			temp.append(nxt)
if len(path)!=n:
	print("NO")
else:
	print("YES")
	ans="\n".join(map(str,path))
	print(ans)