def gcd(a,b):
    x = a
    y = b
    while a%b:
        r = a%b
        a = b
        b = r
    print(str(x)+','+str(y)+'的最大公约数是：'+str(b))
