from itertools import combinations_with_replacement
s,a = input().split()
a = int(a)
for i in combinations_with_replacement(sorted(s),a):
    print(''.join(i))
