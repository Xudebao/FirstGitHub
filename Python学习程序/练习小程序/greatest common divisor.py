# 2017年10月11日11:02:16
# 本程序使用‘欧几里得算法(辗转相除法)’求最大公约数
def gcd(a,b):
    x = a
    y = b
    while a%b:
        r = a%b
        a = b
        b = r
    print(str(x)+','+str(y)+'的最大公约数是：'+str(b))
gcd(1309,765)
