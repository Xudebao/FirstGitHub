# 2017年10月14日16:24:32
# 本程序的功能是：使用函数来处理列表
# 函数在处理列表时，只需将‘列表名’作为函数参数即可

def user(names):
    for each in names:
        temp = 'Hello, '+each.title()+'！'
        print(temp)
user_names = ['xudebao','joshua','cade']
user(user_names)
