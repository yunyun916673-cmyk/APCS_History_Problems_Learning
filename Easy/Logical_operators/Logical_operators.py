import sys
input=sys.stdin.readline
pass_=False
a,b,t=map(int,input().split())
a=1 if a>1 else a
b=1 if b>1 else b
if (a&b)==t:
	print("AND")
	pass_=True
if (a|b)==t:
	print("OR")
	pass_=True
if (a^b)==t:
	print("XOR")
	pass_=True
if not pass_:
	print("IMPOSSIBLE")	