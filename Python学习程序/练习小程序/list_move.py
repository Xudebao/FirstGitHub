# 2017年10月12日10:29:59
# 本程序的功能是：实现不同列表之间的元素的移动

unconfirmed = ['alice','brian','xudebao']
confirmed = []
while unconfirmed : # 只要是unconfirmed列表元素不为空，就将其放入confirmed列表
    confirmed.append(unconfirmed.pop())
print('\nThe following have been confirmed:')
for each in confirmed:
    print(each.title())
