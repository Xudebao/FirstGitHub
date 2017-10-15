# 2017年10月14日15:46:05
# 函数和while循环结合使用
# 函数用于将‘姓’和‘名’连接起来并返回
# while循环用于不断输出、判断、打印

def greeting(first_name,last_name):
    full_name = first_name+' '+last_name
    return full_name.title()
while 1:
    print('\nPlease tell me your name:')
    print("(enter 'q' at any time to quit)")
    f_name = input('First_name:')
    if f_name == 'q':
        break
    l_name = input('Last_name:')
    if l_name == 'q':
        break
    formatted_name = greeting(f_name,l_name)
    print('\nHello, '+formatted_name+'!')
