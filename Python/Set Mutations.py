a = [input().split() for i in range(2)][1]
a = set(map(int,a))
for i in range(int(input())):
    l = input().split()
    if l[0] == 'intersection_update':
        a&=set(map(int,input().split()))
    elif l[0] == 'update':
        a|=set(map(int,input().split()))
    elif l[0] == 'symmetric_difference_update':
        a^=set(map(int,input().split()))
    else:
        a-=set(map(int,input().split()))
print(sum(a))        
