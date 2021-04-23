cube = lambda x: x**3# complete the lambda function 

def fibonacci(n):
    # return a list of fibonacci numbers
    if n==0:
        return []
    if n==1:
        return [0]
    l=[0,1]
    for _ in range(2,n):
        l.append(l[-1]+l[-2])
    return l

if __name__ == '__main__':
    n = int(input())
    print(list(map(cube, fibonacci(n))))
