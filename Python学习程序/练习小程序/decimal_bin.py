# 2017年10月11日10:55:46
# 本程序使用直接法将十进制转换为二进制（不断地整除、取余），
# 将余数‘一位一位’地放入列表（此时为倒置），再通过pop()方法，得到正确的数值
def zhuanhuan(dec):
    temp = []
    result = ''
    while dec: 
        yu = dec%2
        dec = dec//2
        temp.append(yu) # 最终的temp列表为[0, 1, 1, 1, 1, 1]
    while temp:
        result += str(temp.pop())#再将temp列表中的元素不断取出(从右向左)得到result
    return result
print(zhuanhuan(62))
