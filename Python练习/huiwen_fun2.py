def huiwen(temp):
    length = len(temp)
    last = length - 1
    length //= 2
    flag = 1
    for each in range(length):
        if string[each] != string[last]: #此处必须使用中括号
            flag = 0
        last -=1
    if flag == 1:
        return 1
    else :
        return 0
string = input('请输入一串字符：')
if huiwen(string)==1:
    print('是回文！')
else:
    print('不是回文！')
            
    
