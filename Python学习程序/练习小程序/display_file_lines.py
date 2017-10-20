# 2017年10月20日09:55:28
# 本程序的功能是：当用户输入文件名和行数N后，将该文件的前N行内容打印到屏幕上

import os
os.chdir('E:\\')

def filename_line(filename,lines):
    count = 0
    print('\n文件：'+filename+' 的前 '+str(lines)+' 内容如下：\n')
    f = open(filename)
    for each in f:
        count += 1  # 本程序也可不使用count计数，直接使用for i in range(lines)
        print(each)
        if count == lines:
            break
    f.close()

temp1 = input('请输入要打开的文件：')
temp2 = int(input('请输入要显示该文件前几行：'))
filename_line(temp1,temp2)
        
    
