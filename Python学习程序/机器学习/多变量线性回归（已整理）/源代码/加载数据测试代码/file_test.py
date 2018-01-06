def load_exdata(filename):
    data = []  
    with open(filename, 'r') as f:  # f = open(filename, 'r'),打开文件
        for line in f.readlines(): 
            line = line.split(',') #以逗号为界，将每行数据进行分割为三部分，并生成对应的列表
            current = [int(item) for item in line] #数据取整
            #5.5277,9.1302
            data.append(current) #添加列表元素
    print(data)

