def swap_case(s):
    return ''.join([i.upper() if i.islower() else i.lower() for i in s])

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)
