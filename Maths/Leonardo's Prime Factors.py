prime = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79]
x = int(input())
while x>0:
    x = x-1
    n = int(input())
    ans = 0
    counter = 1
    for i in prime:
        if counter*i<=n:
            ans+=1
            counter*=i
        else:
            break
    print(ans) 
