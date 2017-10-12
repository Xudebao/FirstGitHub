# 2017年10月12日14:03:30
# 本程的功能是：将用户的输入填充到字典中
# 本程序中的while循环就是利用标志位来实现，即用标志位来判断循环是否继续

responses = {}  # 定义一个空字典
polling_flag = 1  #标志位

while polling_flag: 
    name = input("\nWhat's your name :")
    hobby = input("What's your hobby :")
    responses[name] = hobby # 将用户输入填充到字典中
    repeat = input('Anyone else want to poll :')
    if repeat == 'NO':
        polling_flag = 0
        
print('\nThe result of polling is following:')

for name,hobby in responses.items(): # for循环将字典遍历
    print(name + "'s"+' hobby '+'is '+hobby+'.')
    
