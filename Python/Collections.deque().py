from collections import deque
d = deque()
for _ in range(int(input())):
    l = input().split()
    if l[0] == 'append':
        d.extend(l[1])
    elif l[0] == 'pop':
        d.pop()
    elif l[0] == 'appendleft':
        d.appendleft(l[1])
    else:
        d.popleft()
print(*d)
