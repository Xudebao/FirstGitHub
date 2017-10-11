bingo = '南京邮电大学'
temp = input('请输入密码：')
while True:
    if temp == bingo:
        print('密码正确！')
        break   # 跳出while循环
    else :
        print('密码错误！')
        temp = input('请重新输入密码：')
        
