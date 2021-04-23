for _ in range(int(input())):
    f=False
    try:
        x = input().strip()
        float(x)
        f=True
        int(x)
        f=False
    except Exception as e:
        pass
    print(f)
