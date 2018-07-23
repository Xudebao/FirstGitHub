#2017年9月19日16:01:17
#本程序用来检测用户输入密码的等级，并且将之显示到屏幕

symbols = r'''!@#$%^&*()_+-=/*{}[]\|'";:/?,.<>'''
chars = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
nums = '0123456789'
num = 0   #记录长度
num1 = 0  #记录所用种类
password = input('Mr Xudebao,Enter your password:')
pas_len = len(password)
while(password.isspace() or pas_len == 0):
    print('Your Password Is Empty ,Please Try Again !')
    password = input('Mr Xudebao,Enter your password:')
    pas_len = len(password)
    
#判断长度
if pas_len < 8: 
    num = 1
elif pas_len < 16:
    num = 2
elif pas_len >= 16:
    num = 3

#判断使用的种类
for each in password:
    if each in symbols:
        num1 +=1
        break
for each in password:
    if each in chars:
        num1 +=1
        break
for each in password:
    if each in nums:
        num1 +=1
        break
    
#结果
if (num == 1):        
    print('Your Level is Low !')
elif (num == 2):
    if (num1 == 1):
        print('Your Level is Not Bad !')
    elif (num1 >= 2):
        print('Your Level is High !')
elif (num == 3):
    print('Your Level is High !')
