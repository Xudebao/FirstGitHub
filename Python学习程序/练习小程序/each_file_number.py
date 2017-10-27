# 2017年10月26日14:01:44
# 本程序的功能是：统计目标文件夹下各个类型文件的个数
import os
os.chdir('E:\\')

all_files = os.listdir(os.curdir)#显示当前目录下的文件夹
type_dict = dict()

for each_file in all_files:
    if os.path.isdir(each_file):  #如果该路径下仍有文件夹
        type_dict.setdefault('文件夹',0) # 设置‘键’文件夹的初值为0
        type_dict['文件夹'] += 1  #文件夹对应的值自增1
    else:
        ext = os.path.splitext(each_file)[1]#分离文件名与扩展名，并取其扩展名
        type_dict.setdefault(ext,0) # 设置‘键’扩展名的初值为0
        type_dict[ext] += 1
for each_type in type_dict.keys(): #对键进行遍历
    print('该文件夹下共有类型为【%s】的文件%d个' %(each_type,type_dict[each_type]))
