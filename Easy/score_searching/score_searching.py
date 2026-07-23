import sys
import bisect
input=sys.stdin.readline
n=int(input())
data=sys.stdin.read().split()
students=list(int(x) for x in data)
students.sort()
print(*students)
thescore=bisect.bisect_left(students,60)
if thescore==0:
	print("best case")
else:
	print(students[thescore-1])
if thescore==n:
	print("worst case")
else:
	print(students[thescore])