from itertools import combinations
n = int(input())
s = input().split()
k = int(input())
l = list(combinations(s , k))
counter=0
for i in l:
    found = False
    for k in i:
        if k == 'a':
            found =True
            break
    if found:
        counter+=1
print('{:.3}'.format(counter/len(l)))
