from itertools import permutations
s,a = input().split()
for i in permutations(sorted(s),int(a)):
    print(''.join(i))
