import sys
input=sys.stdin.readline
s=list(input().strip())
n=len(s)
k=int(input())
def zero():
	global s
	for i in range(0,n,2):
		s[i],s[i+1]=s[i+1],s[i]
def one():
	global s
	for i in range(0,n,2):
		if s[i]>s[i+1]:
			s[i],s[i+1]=s[i+1],s[i]
def two():
	half=n//2
	ts=[]
	for i in range(half):
		ts.append(s[i])
		ts.append(s[i+half])
	s=ts;
for _ in range(k):
	t=int(input())
	if t==0:
		zero()
	elif t==1:
		one()
	else:
		two()
print("".join(s))