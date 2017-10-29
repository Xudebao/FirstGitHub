# 2017年10月29日20:51:58
# 本程序的功能是：测试‘异常’处理机制，以及统计文件的字符数

try:
    f = open('E:\\something1.txt')
    temp = f.read()
except FileNotFoundError:
    msg = print('The File '+'E:\\something1.txt'+' was not found !')
else:
    words = temp.split()#【注意】split是按照空格进行划分字符串
    num_words = len(words)
    print('The File '+'E:\\something1.txt'+' have '+str(num_words)+' words.')
    f.close()
