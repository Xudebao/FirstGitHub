# 2017年10月12日21:04:25
# 本程序的功能；计算圆周率pi值得前32000位中0到9各个'位'的个数
# 最终的结果显示在程序的最后。

#结论：上帝还是相对公平的，因为每位数字出现的次数都大致相等，但是强者总是存在滴！

text = input('请输入这个牛逼的数:')
zero = one = two = three = four = five = six = seven = eight = nine = 0
for each in text:
    if '0' in each:
        zero += 1
    if '1' in each:
        one +=1
    if '2' in each:
        two += 1
    if '3' in each:
        three +=1
    if '4' in each:
        four +=1
    if '5' in each:
        five += 1
    if '6' in each:
        six +=1
    if '7' in each:
        seven += 1
    if '8' in each:
        eight +=1
    if '9' in each:
        nine +=1
print(zero)     # 3184
print(one)      # 3250
print(two)      # 3103
print(three)    # 3180
print(four)     # 3241
print(five)     # 3245
print(six)      # 3216
print(seven)    # 3172
print(eight)    # 3184
print(nine)     # 3224
     










    
        
