from decimal import Decimal
d ={}
for i in range(int(input())):
    x = input().split()
    d[x[0]] = map(float,x[1:])
print(round(Decimal(sum(d[input()])/float(3)),2))
