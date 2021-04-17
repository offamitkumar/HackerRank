from collections import defaultdict
d = defaultdict(list)
n,m = map(int,input().split())
for i in range(1,n+1):
    x = input()
    d[x].append(i)
for i in range(m):
    x = input()
    if x in d:
        print(*d[x])
    else:
        print(-1)
