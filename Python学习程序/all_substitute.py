# 2017年10月20日14:34:21
# 本程序的功能是：对一个文件中的字符串或者单词实现‘全部替换功能’
# count(sub)方法是求出某字符串出现的次数
# replace(a,b)方法是将a替换为b
# print函数格式化输出‘多个’参数，【注】注意使用格式

import os
os.chdir('E:\\')

def all_substitute(filename,old,new):
    f = open(filename)
    count = 0 #用于统计每一行中出现的次数，然后在for循环中进行叠加，得到出现的总次数
    content = [] #该列表用于存储新的文件，存储方法是：一行一行(作为列表的一个元素)地存进去

    for eachline in f: # 先读每一行
        if old in eachline: #再读每一行中的每一个字符串
            count =  count + eachline.count(old)
            eachline = eachline.replace(old,new)
        content.append(eachline)

    print("\n本文一共出现【%d】次'%s'：" %(count,old))
    print('替换之后的文本如下：\n')
    print(content)

temp1 = input('请输入文件名：')
temp2 = input('请输入需要替换的字符串：')
temp3 = input('请输入替换为哪一个字符串：')
all_substitute(temp1,temp2,temp3)

        
            
    
