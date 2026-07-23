import sys
input=sys.stdin.readline
x=input().strip()
a=sum(int(ch) for ch in x[0::2])
b=sum(int(ch) for ch in x[1::2])
print(abs(a-b))