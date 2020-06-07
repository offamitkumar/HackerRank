counts = [0]*100
for i in range(int(input())):
    m,d = map(int,input().split())
    try:counts[int(str(d),m)]+=1
    except:pass
print(sum(c*(c-1)//2 for c in counts))
