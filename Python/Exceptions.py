for i in range(int(input())):
    try:
        x,y = map(int,input().split())
        print(int(x/y))
    except ZeroDivisionError as e:
        print("Error Code: integer division or modulo by zero")
    except Exception as e:
        print("Error Code:",e)

