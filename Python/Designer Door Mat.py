n,m = map(int,input().split())
patt = [('.|.'*int(2*i-1)).center(m,'-') for i in range(1,n//2+1)]
print('\n'.join((patt[::]))+'\n'+"WELCOME".center(m,'-')+'\n'+'\n'.join(patt[::-1]))
