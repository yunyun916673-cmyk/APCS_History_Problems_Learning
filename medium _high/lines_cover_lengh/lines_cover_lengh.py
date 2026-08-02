import sys
input=sys.stdin.readline
n=int(input().strip())
all=[list(map(int,input().split())) for _ in range (n)]
all.sort()
tmp=[]
tmp.append(all[0])
for i in range(1,n):
	li,ri=all[i][0],all[i][1]
	plus=ri-li
	if not plus:
		continue
	if li<=tmp[-1][1]:
		tmp[-1][1]=max(tmp[-1][1],ri)
	else:
		tmp.append([li,ri])
ans=0
for l in tmp:
	ans+=l[1]-l[0]
print(ans)