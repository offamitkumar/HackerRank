for _ in range(int(input())):
    a,b = [input().split() for i in range(4)][1::2]
    a =set(map(int,a))
    b =set(map(int,b))
    print(a&b==a)
