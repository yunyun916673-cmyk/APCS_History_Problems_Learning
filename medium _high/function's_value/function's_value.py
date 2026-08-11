import sys
input=sys.stdin.readline
sys.setrecursionlimit(200005)
line=list(map(str,input().split()))
pos=0
def F(x):
    return 2*x-3
def G(x,y):
    return 2*x+y-7
def H(x,y,z):
    return 3*x-2*y+z
def dfs():
    global pos
    typ=line[pos]
    pos+=1
    if typ=="f":
        return F(dfs())
    elif typ=="g":
        return G(dfs(),dfs())
    elif typ=="h":
        return H(dfs(),dfs(),dfs())
    else:
        return int(typ)
print(dfs())
