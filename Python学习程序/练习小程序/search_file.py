# 2017年10月26日14:43:22
# 本程序的功能：在一个文件夹及其子文件夹中，搜索特定的文件

import os

def search_file(start_dir,target):
    os.chdir(start_dir)

    for each_file in os.listdir(os.curdir):
        if each_file == target:
            print(os.getcwd() + os.sep + each_file)
          # getcwd(),返回当前工作目录；os.sep,输出Windows操作系统下的路径分隔符
        if os.path.isdir(each_file):
            search_file(each_file,target) #采用递归的方式，在子文件夹中进行搜索
            os.chdir(os.pardir) #【记住】在递归调用后要返回上一级目录
        

start_dir = input('请输入待查找的初始目录：')
target = input('请输入需要查找的目标文件：')
search_file(start_dir,target)
