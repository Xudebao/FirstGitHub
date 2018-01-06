
# coding: utf-8

# ## 多变量线性回归(Linear Regression with Multiple Variables)

# In[4]:

#初始化工作
import random
import numpy as np
import matplotlib.pyplot as plt

# This is a bit of magic to make matplotlib figures appear inline in the notebook
# rather than in a new window.
get_ipython().magic('matplotlib inline')
plt.rcParams['figure.figsize'] = (10.0, 8.0) # set default size of plots
plt.rcParams['image.interpolation'] = 'nearest'
plt.rcParams['image.cmap'] = 'gray'

# Some more magic so that the notebook will reload external python modules;
# see http://stackoverflow.com/questions/1907993/autoreload-of-modules-in-ipython
get_ipython().magic('load_ext autoreload')
get_ipython().magic('autoreload 2')


# ### 1、加载数据
#  数据格式为：
#  
# X1,X2,Y
# 
# 2104,3,399900
# 
# 1600,3,329900
# 
# 2400,3,369000
# 
# 1416,2,232000
# 
# 将数据逐行读取，用逗号切分，并放入np.array
# 

# In[5]:

#加载数据
def load_exdata(filename):
    data = []  
    with open(filename, 'r') as f:  # f = open(filename, 'r'),打开文件
        for line in f.readlines(): 
            line = line.split(',') #以逗号为界，将每行数据进行分割为三部分，并生成对应的列表
            current = [int(item) for item in line] #数据取整
            #5.5277,9.1302
            data.append(current) #添加列表元素
    return data

data = load_exdata('ex1data2.txt'); # 得到数据列表（2维，shape=（47,3））
data = np.array(data,np.int64)  # 设置data元素为64位整型变量

x = data[:,(0,1)].reshape((-1,2)) #将所有元素变为两列，行数由numpy自动计算
y = data[:,2].reshape((-1,1)) #取出第三列元素将所有元素变为只有一列
m = y.shape[0] #读取y的第一维的长度，y为一维数组

# Print out some data points
print('First 10 examples from the dataset: \n')
print(' x = ',x[range(10),:],'\ny=',y[range(10),:]) #打印x，y的前10组数据，(这里打印出的是特征缩放之前的数据)


# ## 2、通过梯度下降求解theta
# 
# 1. 面对多维特征问题的时候，要保证特征具有相近的尺度，这将帮助梯度下降算法更快地收敛。解决的方法是尝试将所有特征的尺度都尽量缩放到-1 到 1 之间，最简单的方法就是(X - mu) / sigma，其中mu是平均值， sigma 是标准差。
# 2. 损失函数和单变量一样，依然计算损失平方和均值
# 3. X需要加上一列全为1，即用来表示x0

# In[16]:

#特征缩放
def featureNormalize(X):
    X_norm = X;
    mu = np.zeros((1,X.shape[1])) #生成1行X.shape[1]列的零数组(此处为2列),即[[ 0.,  0.]]
    sigma = np.zeros((1,X.shape[1])) #sigma的初始值[[ 0.,  0.]]
    for i in range(X.shape[1]):
        mu[0,i] = np.mean(X[:,i]) # 分别计算两列(x1,x2)的均值
        sigma[0,i] = np.std(X[:,i])     # 分别计算两列(x1,x2)的标准差
#     print(mu) 此处可用来验证均值
#     print(sigma) 同上
    X_norm  = (X - mu) / sigma #特征缩放公式，此处因为X，mu，sigma的列数相同(都为2)，故可以进行运算
    return X_norm,mu,sigma #返回缩放后的数据以及均值mu，标准差sigma

#计算代价函数
def computeCost(X, y, theta):
    m = y.shape[0]
#   J = (np.sum((X.dot(theta) - y)**2)) / (2*m)#每次取一组theta值，并与所有样例的值相乘。
    C = X.dot(theta) - y
    J2 = (C.T.dot(C))/ (2*m) #C.T.dot(C)，表示C的转置乘C，即得C的平方
    return J2

#梯度下降
def gradientDescent(X, y, theta, alpha, num_iters):#num_iters为迭代次数
    m = y.shape[0]
    #print(m)
    # J_history存储历史误差，1000行1列
    J_history = np.zeros((num_iters, 1)) 
    for iter in range(num_iters):
        # 对J求导，得到 alpha/m * (WX - Y)*x(i)， (3,m)*(m,1)  X (m,3)*(3,1) = (m,1)
        theta = theta - (alpha/m) * (X.T.dot(X.dot(theta) - y)) #更新theta值
        J_history[iter] = computeCost(X, y, theta)#存储更新的损失函数值(因为产生了新的theta) 
    return J_history,theta
    

iterations = 10000  #迭代次数
alpha = 0.01    #学习率
x = data[:,(0,1)].reshape((-1,2))
y = data[:,2].reshape((-1,1))
m = y.shape[0]
x,mu,sigma = featureNormalize(x)#返回缩放后的样例的值以及均值mu，标准差sigma
X = np.hstack([x,np.ones((x.shape[0], 1))])#hstack为数据连接操作
# X = X[range(2),:]
# y = y[range(2),:]

theta = np.zeros((3, 1))#theta的初始值都为零(3个)

j = computeCost(X,y,theta) # 计算损失函数值，这行也可以不要，因为在计算梯度下降时会进行损失函数的计算
J_history,theta = gradientDescent(X, y, theta, alpha, iterations)#更新损失函数值即theta


print('Theta found by gradient descent',theta)#最后theta的值




# ### 绘制迭代收敛图

# In[17]:

plt.plot(J_history)
plt.ylabel('lost');
plt.xlabel('iter count')
plt.title('convergence graph')


# ### 预测

# In[18]:

def predict(data):
    testx = np.array(data)
    testx = ((testx - mu) / sigma)#测试数据的特征缩放
    testx = np.hstack([testx,np.ones((testx.shape[0], 1))])#数据连接
    price = testx.dot(theta) #计算终值
    print('price is %d ' % (price))

predict([1650,3])


# In[ ]:



