n,m = map(int,input().split())
l =[input() for i in range(n)] 
k = int(input())
print(*sorted(l, key=lambda r: int(r.split()[k])),sep='\n')
