# 2017年10月14日16:36:02
# 本程序的功能是：展示了完全使用函数来处理数据的过程
# 使用函数的原则：
# 每个函数只负责一项具体的工作，这样有助于将复杂的问题分成一系列的步骤
#【注意】：在函数体内部的变量一律使用形参，不要使用实参

unprinted_models = ['iphones','huawei','xiaomi','samsung']
printed_models = []
def printings(prints,hasprinted):#函数体内部的变量一律使用形参prints和hasprinted
    while prints:
        print('The models are printing: ') 
        for each in prints:
            print(each.title())
        temp = prints.pop()
        hasprinted.append(temp)

def printed(printeds):
    print('\nThe models were printed:')
    for each in printeds:
        print(each.title())
        
printings(unprinted_models,printed_models)
printed(printed_models)


