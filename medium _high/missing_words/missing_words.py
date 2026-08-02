import sys
from itertools import product
input=sys.stdin.readline
U,L,S=input().split()
L=int(L)
sz=len(S)
every=set()
for i in range(sz):
	every.add(S[i:i+L])
for s in product(sorted(U),repeat=L):
	test="".join(s)
	if test not in every:
		print(test)
		break