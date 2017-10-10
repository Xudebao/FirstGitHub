temp = input('Enter: ')
while not temp.isdigit():
    temp = input("抱歉，您的输入类型有误，请输入一个整数：")
str1 = str(temp)
print('您输入的是：'+str1)

