from collections import Counter 
n = int(input())
l = Counter(map(int,input().split())) 
counter=0
for i in range(int(input())):
    x,y = map(int,input().split())
    if l[x]>=1:
        l[x]-=1
        counter+=y
print(counter)
