# 2017年10月11日12:42:07
# 本程序的功能是：判断用户的输入是否是‘纯数字’类型
# 使用isdigit()方法实现

temp = input('Enter: ')
while not temp.isdigit():
    temp = input("抱歉，您的输入类型有误，请输入一个整数：")
str1 = str(temp)
print('您输入的是：'+str1)

