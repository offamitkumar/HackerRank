a,b = [input().split() for i in range(4)][1::2]
print(len(set(map(int,a)) & set(map(int,b))))
