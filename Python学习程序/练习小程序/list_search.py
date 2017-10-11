# 2017年10月11日13:02:46
# 本程序的功能是：在目标列表中查询子列表的元素是否存在

available_foods = ['醋','香菜','蒜泥','辣油'] #目标列表
requested_foods = ['醋','沙拉','辣油','奶油'] #子列表
temp1 = []
temp2 = []
for requested_food in requested_foods:
    if requested_food in available_foods:
        temp1.append(requested_food)
       # print(requested_food + 'is requested ！')
    else:
        temp2.append(requested_food)
        #print(requested_food + 'is inrequested !')
print('以下的Food没有：')
print(temp1)
print('以下的Food尚有：')
print(temp2)



