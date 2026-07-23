import sys
input = sys.stdin.readline 
a,b=map(int,input().split())
n=int(input())
ans=0
for i in range(n):
	t=int(input())
	if t%(a+b)>a:
		ans+=a+b-t%(a+b)
print(ans)
