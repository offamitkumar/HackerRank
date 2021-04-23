import re
s,k =input(),input()
r = re.compile(k)
temp = r.search(s)
if not temp:
    print('(-1, -1)')
else:
    while temp:
        print((temp.start() , temp.end()-1))
        temp = r.search(s, temp.start()+1)

