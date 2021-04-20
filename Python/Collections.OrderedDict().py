from collections import OrderedDict
d = OrderedDict()
for _ in range(int(input())):
    itm,tmp,pr = input().rpartition(' ')
    if itm in d.keys():
        d[itm]+=int(pr)
    else:
        d[itm]=int(pr)
for l in d:
    print(l,d[l],sep=' ')
