# 2017年10月26日15:25:41
# 本程序的功能是：在指定的目录下搜索视频格式文件(如mp4,rmvb,avi),
# 并创建一个文件存放所有找到的路径

import os

def search_file(start_dir,target):
    os.chdir(start_dir)

    for each_file in os.listdir(os.curdir):
        ext = os.path.splitext(each_file)[1] # 分离出文件的扩展名
        if ext in target:
            vedio_list.append(os.getcwd() + os.sep + each_file + os.linesep)

        if os.path.isdir(each_file):
            search_file(each_file,target)#递归调用
            os.chdir(os.pardir)#递归调用后，返回上一级目录

start_dir = input('请输入待查找的初始目录：')

target = ['.mp4','.avi','.rmvb'] # 预设的文件扩展名
vedio_list = []  #用于存放找到的扩展名
search_file(start_dir,target)


f = open(start_dir + os.sep + 'vediolist.txt','w')#在初始文件夹下以写入的模式打开一个文件夹vediolist.txt
f.writelines(vedio_list)
f.close()
