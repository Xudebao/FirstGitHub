# 2017年10月29日20:41:28
# 本程序的功能是：测试‘异常’，即try-except-else语句

print('请输入两个数，然后做除法运算')
print('按q退出程序\n')

while 1:
    first_number = input('请输入第一个数：')
    if first_number == 'q':
        break
    second_number = input('请输入第二个数：')
    if second_number == 'q':
        break
    try:
        answer = int(first_number)/int(second_number)
    except ZeroDivisionError:
        print('0不能做除数')
    else:
        print(answer)

