# 2017年10月11日12:12:31
# 本程序用于求n的阶乘，主要用for循环实现
def factorial(n):
    result = n
    for i in range(1,n):
        result *= i
    return result
number = int(input('enter a number:'))
value = factorial(number)
print('%d 的阶乘是：%d'%(number,value))
    
