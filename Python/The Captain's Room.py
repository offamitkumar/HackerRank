l = [input().split() for i in range(2)][1]
s=set()
m=set()
for i in l:
    s.add(i) if i not in s else m.add(i)
print((s-m).pop())
