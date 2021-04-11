d = dict()
for i in range(int(input())):
    x = input()
    d.setdefault(x,0)
    d[x]+=1
print(len(d))
print(*d.values())
