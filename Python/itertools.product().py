from itertools import product
l = [map(int,input().split()) for i in range(2)]
print(*product(*l))

