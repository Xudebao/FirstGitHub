# 2017年10月11日12:18:33
# 本程序用于将列表中的字符串剔除，从而提取出‘纯数字’的列表
# 主要应用isinstance()方法，和remove()方法
listmix = [2,3,4,'ed',5,'fd']
print(listmix)
for each in listmix:
    if isinstance(each,str):
        listmix.remove(each)
listpure = listmix[:]
print(listpure)
print(sum(listmix))

