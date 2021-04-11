import datetime 
ft = '%a %d %b %Y %H:%M:%S %z'
for _ in range(int(input())):
    print(int(abs(datetime.datetime.strptime(input(), ft) - datetime.datetime.strptime(input(),ft)).total_seconds()))
