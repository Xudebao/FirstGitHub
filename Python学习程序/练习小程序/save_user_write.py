# 2017年10月19日15:05:19
# 本程序的功能是：接受用户的输入并保存为新的文件
import os
os.chdir('E:\\') #插入os模块，设定当前操作的目录为E盘

def file_write(file_name):
    
    f = open(file_name,'w')  #以写入的方式打开一个文件名为file_name的文件
    print('请输入内容【单独输入":w"保存退出】：')

    while 1:
        write_some = input() #此处input()中不能有文字，否则每次判断都会打印出来
        if write_some != ':w':
            f.write('%s\n' % write_some)#此处\n可以让用户输入时，每按一次回车就会换行保存
        else:
            break
    f.close()  #记得关闭文件
    
file_name = input('请输入文件名：')
file_write(file_name)




