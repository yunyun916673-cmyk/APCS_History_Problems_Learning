import sys
input=sys.stdin.readline
n=int(input())
buil=list(map(int,input().split()))
cnt,ans=1,1
for fi,bi in zip(buil,buil[1:]):
	if (fi>bi):
		cnt+=1
		ans=max(ans,cnt)
	else:
		cnt=1
print(ans)