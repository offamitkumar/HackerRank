from itertools import groupby
s = input()
l = []
for i,j in groupby(s):
    l.append((len(list(j)),int(i)))
print(*l,sep=' ')
