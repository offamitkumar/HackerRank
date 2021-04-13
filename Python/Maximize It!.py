k,m = map(int,input().split())
ans = 0 

def sol(l , a , i):
    global ans
    if i == k:
        ans = max(ans , a%m)
        return 
    for j in l[i]:
        a += j*j
        sol(l, a, i+1)
        a -= j*j


l = [list(map(int,input().split()))[1:] for i in range(k)]
sol(l,0,0)
print(ans)
