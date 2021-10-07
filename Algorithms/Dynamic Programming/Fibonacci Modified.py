t1,t2,n = map(int,input().split()) 
for i in range(3,n+1):
    temp = t1 + t2*t2
    t1 =t2
    t2 = temp
print(temp)
