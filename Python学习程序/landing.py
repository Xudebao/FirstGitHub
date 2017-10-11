# 2017年10月10日15:41:41
# 本程序是一个模拟登录系统的程序，使用‘新建’，‘登录’，‘调用’3个函数
# 前两个（新建、登录）相当于子函数，最后一个‘调用’相当于主函数

user_data = {}  # 定义一个空字典
def new_user(): # 定义一个“新建用户”函数
    while 1:
        name = input('请输入用户名：')
        if name in user_data:
            print('此用户名已被注册，请重新输入：')
            continue
        else:
            break
    passwd = input('请输入密码：')
    user_data[name] = passwd
    print('注册成功，赶紧登录吧^_^')
def old_user(): # 定义一个“登录账号”函数
    while True:
        name = input('请输入用户名：')
        if name not in user_data:
            print('您输入的用户名不存在，请重新输入：')
            continue
        else:
            break
    passwd = input('请输入密码：')
    pwd = user_data[name]
    if passwd == pwd:
        print('欢迎进入XXOO系统，请点击右上角的X结束！')
    else:
        print('密码错误！')
def showmenu():
    prompt = '''
|---新建用户:N/n---|
|---登录账号:E/e---|
|---退出程序:Q/q---|
|---请输入指令代码：'''
    while 1:
        choice = input(prompt)
        if choice in 'NnEe':
            if choice == 'n' or choice == 'N':
               new_user()
            if choice == 'e' or choice == 'E':
               old_user()
        elif choice in 'qQ':
            break
        elif choice not in 'NnEeQq':
            print('您输入的指令代码错误，请重新输入：')          
showmenu()
          



        
