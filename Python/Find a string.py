def count_substring(string, sub_string):
    counter = 0
    i=0
    while i < len(string):
        j = 0 
        temp = i
        while (temp<len(string)) and (j < len(sub_string)):
            if string[temp] != sub_string[j]:
                break
            j+=1
            temp+=1
        counter += (j == len(sub_string))
        i+=1
    return counter

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)
