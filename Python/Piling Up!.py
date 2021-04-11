for _ in range(int(input())):
    s = list(map(int,[input().split() for i in range(2)][1]))
    i,j = 0, len(s)-1
    maxR=s[i]
    maxL=s[j]
    changed=True
    while i<j and changed:
        changed=False
        if s[i]>s[j] and s[i]>=s[i+1]:
            changed=True
            i+=1
            maxR = s[i]
        elif s[j]>=s[j-1]:
            changed=True
            j-=1
            maxL = s[j]
    if (i==j):
        print("Yes")
    else:
        print("No")
