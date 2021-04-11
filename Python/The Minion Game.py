def minion_game(string):
    b=0
    k=0
    vow='AIEOUaeiou'
    for i in range(len(s)):
        if s[i] in vow:
            k+=(len(s)-i)
        else:
            b+=(len(s)-i)
    if b==k:
        print("Draw")
    elif b>k:
        print(f'Stuart {b}')
    else:
        print(f'Kevin {k}')

if __name__ == '__main__':
    s = input()
    minion_game(s)
