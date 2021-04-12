a = set(input().split())
flag = True
for _ in range(int(input())):
    b = set(input().split())
    if b&a==b and len(a-b):
        flag&=1
    else:
        flag=0
print(True if flag else False)
