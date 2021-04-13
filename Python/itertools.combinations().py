from itertools import combinations 
s,a = input().split()
a = int(a)
for i in range(1,a+1):
    for j in combinations(sorted(s),i):
        print(''.join(j))
