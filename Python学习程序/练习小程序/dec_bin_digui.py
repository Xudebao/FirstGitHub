# 2017年10月11日10:34:16
# 本程序使用递归算法将十进制转换为二进制，不断地调用自身函数dec2bin()对2整除，
# 然后再将整除2之后的结果对2进行取余。
def dec2bin(dec):
    result = ''
    if dec:
        result = dec2bin(dec//2)
        return result + str(dec%2)
    else:
        return result
print(dec2bin(62))
