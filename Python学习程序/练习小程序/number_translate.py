# 2017年10月11日12:26:51
# 本程序说明了数据格式符的使用（使用的格式类型以及语句格式）
temp = input('请输入一个数：')
print('该十进制数为： '+temp)
num = int(temp)
print('十进制 -> 十六进制 : %d -> 0x%x' % (num, num))
print('十进制 -> 八进制 : %d -> 0o%o' % (num, num))
print('十进制 -> 二进制 : %d -> ' % num, bin(num))


    
