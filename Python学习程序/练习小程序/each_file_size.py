# 2017年10月26日14:22:17
# 本程序的功能是：计算目标文件夹下每个文件的大小

import os
os.chdir('E:\\')

all_files = os.listdir(os.curdir)#显示当前目录下的文件夹，并返回一个列表
file_dict = dict()

for each_file in all_files:
    if os.path.isfile(each_file): #如果该路径下存在文件
        file_size = os.path.getsize(each_file) #返回文件的大小
        file_dict[each_file] = file_size #将‘值’存进对应的‘键’

for each in file_dict.items(): #遍历‘键’和‘值’
    print('%s【%dBytes】'%(each[0],each[1]))

#对于输出‘键-值’对还可以用下面的方法：
#for key,value in file_dict.items(): #遍历‘键’和‘值’
    #print('%s【%dBytes】'%(key,value))
