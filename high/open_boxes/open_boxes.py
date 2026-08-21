import sys
from collections import deque
input=sys.stdin.readline
n,m,k=map(int,input().split())
keys=set()
pos=0
for i in map(int,input().split()):
	if pos==0:
		t=i
	else:
		keys.add(i)
	pos+=1
can_open=[[] for _ in range(m)]
cnt=[k for _ in range(n)]
temp=deque()
for i in range(n):
	for j in map(int,input().split()):
		can_open[j].append(i)
		if j in keys:
			cnt[i]-=1
	if cnt[i]==0:
		temp.append(i)
gifts=[]
for _ in range(n):
	gifts.append(list(map(int,input().split())))
total=0
while temp:
	box=temp.popleft()
	total+=1
	for key in gifts[box]:
		if key in keys:
			continue
		keys.add(key)
		for b in can_open[key]:
			cnt[b]-=1
			if cnt[b]==0:
				temp.append(b)
print(total)
