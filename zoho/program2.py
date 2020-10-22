import math
a=[10,36,54,89,12]
a=sorted(a)
print(a)
for i in a:
    num=math.sqrt(i)
    if int(num+0.5)**2==i:
        print('<',i,',5 >')
    elif i%4==0 and i%6==0:
        print('<',i,',4 >')
    elif i%2==0:
        print('<',i,',3 >')


