# 2017年10月12日10:57:40
# 本程序的功能是：通过while循环来删除列表中的所有的特定（相同）元素

people = ['xudebao','dog','joshua','dog','dog','kaide']
print(people)
while 'dog' in people : # 循环检测列表people，只要含有dog就将其删除
    people.remove('dog')
print(people)
