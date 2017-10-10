def huiwen(string):
    list1 = list(string)
    list2 = reversed(list1)
    if list1 == list(list2):
        return 'Yes'
    else:
        return 'No'
print(huiwen('上海自来水来自海上'))

