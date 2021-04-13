c = '' 
stk=[]
stk.append(c)
for _ in range(int(input())):
    l = input().split()
    if l[0] == "1":
        c+=l[1]
        stk.append(c)
    elif l[0] == "2":
        c = c[0:len(c)-int(l[1]):]
        stk.append(c)
    elif l[0] == "3":
        print(c[int(l[1])-1])
    else:
        stk.pop()
        c = stk[len(stk)-1]


