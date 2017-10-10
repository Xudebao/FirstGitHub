listmix = [2,3,4,'ed',5,'fd']
print(listmix)
for each in listmix:
    if isinstance(each,str):
        listmix.remove(each)
listpure = listmix[:]
print(listpure)
print(sum(listmix))

