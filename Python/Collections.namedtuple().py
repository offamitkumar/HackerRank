l = [input().split() for i in range(2)]
ind = l[1].index('MARKS')
m = [int(input().split()[ind]) for i in range(int(l[0][0]))]
print(sum(m)/int(l[0][0]))
