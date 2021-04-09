l = []
for i in range(int(input())):
    l.append([input(),float(input())])
s = sorted(list(set([marks for name, marks in l])))[1] 
print('\n'.join([a for a,b in sorted(l) if b == s]))
