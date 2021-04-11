a,b = [set(input().split()) for i in range(4)][1::2]
print('\n'.join(sorted(a^b, key=int)))
