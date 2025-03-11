#建议调试程序时，先把不需要的代码注释掉，然后逐步解除注释，逐步调试。
#coding=UTF-8
# Description: Python基础学习

# Description:赋值运算符的使用：从右到左
"""
a=20
链式赋值:a=b=c=100
字符串分解赋值:a,b,c,d="room"
"""

# Description:选择结构
'''
if条件语句
if-else条件语句
if-elif-else条件语句
结构:if 条件:
        语句块
    elif 条件:
        语句块
    else:
        语句块
三元运算符:如果条件为真,返回真的结果,否则返回假的结果
    结构:真的结果 if 条件 else 假的结果
    示例:x if x < y else y
'''
x=input("请输入一个字符串:")                  #判断是不是空字符串
if x:
    print("是一个非空字符串")
if not x:
    print("是一个空字符串")

'''
模式匹配:match
结构:match 匹配对象:
        case 匹配值1:
            语句块
        case 匹配值2:
            语句块
        case _:
            语句块
'''



# Description:循环结构
'''
while循环
    while 条件:
        语句块

存在while-else 结构
for循环
    range函数:range(起始值,结束值,步长),其中,起始值和步长可以省略,默认起始值为0,步长为1,结束值必须有;数据的范围是[起始值,结束值).
    for 变量 in range(起始值,结束值,步长):
        语句块

break:跳出循环,用法与C语言相同
continue:跳过本次循环,继续下一次循环,用法与C语言相同
pass:空语句,用于占位,不做任何事情;用于保持程序结构的完整性.在编写程序的过程中防止报错碍眼使用.
'''
#打印菱形
a=eval(input("请输入菱形的行数:"))
for i in range(1,a+1):
    if i <=a//2+1:
        for u in range(1,a//2+i+1):
            if u<=a//2+1-i:
                print(" ",end="")
            else:
                print("*",end="")
    else:
        for u in range(1,a//2+a-i+2):
            if u<=a//2-a+i:
                print(" ",end="")
            else:
                print("*",end="")
    print('\n',end='')
    

#打印空心菱形
a=eval(input("请输入菱形的行数:"))
for i in range(1,a+1):
    if i <=a//2+1:
        for u in range(1,a//2+i+1):
            if u==a//2+2-i or u==a//2+i:
                print("*",end="")
            else:
                print(" ",end="")
    else:
        for u in range(1,a//2+a-i+2):
            if u==a//2-a+i+1 or u==a//2+a-i+1:
                print("*",end="")
            else:
                print(" ",end="")
    print('\n',end='')

