def merge_the_tools(string, k):
    for st in zip(*([iter(string)] * k)):
        s = set()
        l=[]
        for i in st:
            if i not in s:
                l.append(i)
                s.add(i)

        print(''.join(l))
if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)
