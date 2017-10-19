# 2017年10月19日16:11:19
# 本程序的功能是：比较两个文件是否完全相同，如果不同，显示出一共有几行不同
# 并且显示出具体是哪几行。

import os
os.chdir('E:\\')  # 设定当前目录

def file_compare(file1,file2):
    f1 = open(file1)
    f2 = open(file2)
    count = 0    #记录比较的次数
    differ = []  #记录文件不同的行数

    for line1 in f1 :  #逐行比较
        line2 = f2.readline()
        count += 1
        if line1 != line2:
            differ.append(count)

    f1.close()
    f2.close()
    return differ
file1 = input('请输入第一个比较的文件名：')
file2 = input('请输入第二个比较的文件名：')

differ = file_compare(file1,file2)

if len(differ) == 0:
    print('两个文件完全一样！')
else:
    print('两个文件共有【%d】处不同：' %len(differ))
    for each in differ:
        print('第 %d 行不一样' % each)




