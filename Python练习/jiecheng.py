def factorial(n):
    result = n
    for i in range(1,n):
        result *= i
    return result
number = int(input('enter a number:'))
value = factorial(number)
print('%d 的阶乘是：%d'%(number,value))
    
