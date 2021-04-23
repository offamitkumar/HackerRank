n = int(input())
l = input().split()
print(all([int(j)>0 for j in l]) and any([j==j[::-1] for j in l]))
