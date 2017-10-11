# 2017年10月11日11:12:16
# 本程序使用函数及reversed方法来判断字符串是否为‘回文联’
def huiwen(string):
    list1 = list(string)
    list2 = reversed(list1)
    if list1 == list(list2): # 此处必须再用list命令将list2转换为列表
        return 'Yes'
    else:
        return 'No'
print(huiwen('上海自来水来自海上'))

