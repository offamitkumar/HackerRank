def print_formatted(number):
    n = len(str(bin(number)))
    for i in range(1,number+1):
        print(str(i).rjust(n-2)+str(oct(i))[2::].rjust(n-1,' ')+str(hex(i).upper())[2::].rjust(n-1,' ')+str(bin(i))[2::].rjust(n-1,' '))

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
