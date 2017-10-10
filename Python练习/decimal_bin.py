def zhuanhuan(dec):
    temp = []
    result = ''
    while dec:
        yu = dec%2
        dec = dec//2
        temp.append(yu)
    while temp:
        result += str(temp.pop())
    return result
