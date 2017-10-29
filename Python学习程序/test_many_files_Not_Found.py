# 2017年10月29日21:17:10
# 本程序的功能是：测试多个文件的字符的数目，其中主要测试‘异常’的用法

# 从本程序中，就能很好的体现出使用‘异常’的好处
# 其好处有两点，1、在出现异常时不会给出traceback，而是用了更清楚错误表达
# 2、当遇到异常并给出错误之后，程序可以继续运行而不中断，这就体现了程序的‘健壮性’

import os
os.chdir('E:\\')

def count_words(filename):
    """计算一个文件大致包含多少个单词"""
    try:
        f = open(filename)
        temp = f.read()
    except FileNotFoundError:
        msg = print('The File '+filename+' was not found !')
    else:
        #计算文件包含多少个单词
        words = temp.split()
        num_words = len(words)
        print('The File '+filename+' have '+str(num_words)+' words.')
        f.close()

filenames = ['test_cell.txt','cell.txt','test_limited_function.txt','function.txt','test_orbit.txt','test_patten.txt']      
for each in filenames:
    count_words(each)

#程序执行的结果如下：

#The File test_cell.txt have 182 words.
#The File cell.txt was not found !
#The File test_limited_function.txt have 387 words.
#The File function.txt was not found !
#The File test_orbit.txt have 397 words.
#The File test_patten.txt have 376 words.

# 如果没有‘异常’机制，那么当执行到cell.txt,发现这个文件不存在时，程序就会报错，并且终止运行







    
