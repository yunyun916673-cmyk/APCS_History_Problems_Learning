import sys
input=sys.stdin.readline
sys.setrecursionlimit(200000)
n,m=map(int,input().split())
Wt=[0 for _ in range(n)]
ship=[(0,0) for _ in range(2*n)]
for w in map(int,input().split()):
    Wt.append(w);
goods=list(map(int,input().split()))
for _ in range(n-1):
    a,b,c=map(int,input().split())
    ship[a]=(b,c)
def dfs(pwd):
    if pwd<n:
        a,b=ship[pwd][0],ship[pwd][1]
        dfs(a)
        dfs(b)
        if pwd!=1:
            Wt[pwd]+=Wt[a]+Wt[b]
dfs(1)
pos,good=0,0
def put_good(pwd):
    global pos,good
    if pwd<n:
        a,b=ship[pwd]
        nxt=b if Wt[a]>Wt[b] else a
        put_good(nxt)
    else:
        pos=pwd
    if pwd!=1:
        Wt[pwd]+=good
tmp=[]
for g in goods:
    good=g
    put_good(1)
    tmp.append(pos)
ans=" ".join(map(str,tmp))
print(ans)
