# 2017年10月20日10:27:20
# 本程序的功能是：针对一个文件，对用户指定的‘行数’进行输出

import os
os.chdir('E:\\')

def filename_line(filename,lines_start,lines_end):
    count = 0 #用于记录需要‘过滤’掉的行数
    count1 = 0 #用于记录需要打印的总行数
    
    print('\n文件：'+filename+' 的第 '+str(lines_start)+' 行到 '+'第 '+str(lines_end)+' 行内容如下：\n')
    f = open(filename)
    while count != lines_start-1: #white循环将输出起始行的文本读出（即‘过滤’掉）
        f.readline()
        count +=1 
        
    for each in f:  #for循环用于把剩下的文本读出
        print(each)
        count1 += 1
        if count1 == lines_end-lines_start+1:
            break
            
    f.close()

temp1 = input('请输入要打开的文件：')
temp2 = int(input('请输入要显示该文件的起始行：'))
temp3 = int(input('请输入要显示该文件的终止行：'))
filename_line(temp1,temp2,temp3)
# 另一种文本的输入及处理：
# 例如：输入 3:10 ,即代表打印出第3行到第10行
# 那么就可以使用split(sep=None,maxsplit=-1)命令把3:10分割成3,10两部分，并把他们按列表进行存储
# t = '3:4'
# (q,w) = t.split(':')
# 通过以上两行命令，就可以得到q = 3，w = 4
