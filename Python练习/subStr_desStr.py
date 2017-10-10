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
    
    
