# 2017年10月10日16:17:18
# 本程序是一个通讯录程序，主要功能有：新建、查询、删除、退出
# 【注】：对于‘新建’和‘查询’联系人的时候，都要先查询此联系人是否存在

print('|---欢迎进入通讯录程序---|')
print('|---1：查询联系人资料---|')
print('|---2：插入新的联系人---|')
print('|---3：删除已有联系人---|')
print('|---4：退出通讯录程序---|')
contacts = dict() #定义一个空字典
while 1:
    temp = int(input('请输入指令代码：'))
    if temp == 1:
        name = input('请输入联系人：')
        if name in contacts:
            print(name + ':'+contacts[name])
        else:
            print('您输入的姓名不在通讯录中！')
    elif temp == 2:
        name = input('请输入联系人姓名：')
        if name in contacts:
            print('您输入的姓名已在通讯录中-->>',end='')
            print(name + ':'+contacts[name])
            if input('是否修改用户资料（YES/NO）：')=='YES':
                contacts[name] = input('请输入用户联系电话：')
        else:
            contacts[name] = input('请输入用户联系电话')
    elif temp == 3:
        name = input('请输入联系人姓名：')
        if name in contacts:
            del(contacts[name])
        else:
            print('您输入的联系人不存在！')
    elif temp == 4:
        break
    else :
        print('您输入的指令代码有误，请重新输入！')
        temp = int(input('\n请输入指令代码：'))
print('|---感谢使用通信录程序---|')
        
       
       
    
    
