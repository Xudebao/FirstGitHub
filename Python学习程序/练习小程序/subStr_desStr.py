# 2017年10月11日12:31:44
# 本程序的功能是：统计一个子字符串在目标字符串中出现的次数
#【注】：此处的子字符串的只能含有两个字符，因为在下面的程序中只是使用了2次for循环

def findstr(desStr,subStr):
    count = 0
    len_words = len(desStr)
    if subStr not in desStr:
        print('该字符串没有出现在目标字符串中！')
    else:
        for each in range(len_words-1):
            if subStr[0] == desStr[each]:
                if subStr[1] == desStr[each + 1]:# 此处有each+1，故在前面的的range中应该使用len_words - 1
                    count +=1
    print('子字符串 '+subStr+' 在目标字符串 '+desStr+' 中出现的次数为：'+str(count))
    
    
