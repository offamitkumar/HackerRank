n,x = map(int,input().split())
l = [list(map(float,input().split())) for _ in range(x)]
for i in zip(*l):
    print(sum(i)/x)
