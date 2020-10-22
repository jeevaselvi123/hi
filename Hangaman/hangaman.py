import random,re
country=['russia','canada','china','unitedstates','brazil','australia','india','argentina','kazakhstan','sudan']
str1=random.choice(country)
str2='-'*len(str1)
str2=list(str2)
n=len(str1)
print(str1)
temp=""
n1=3
while n1!=0:
    ip=input("Enter the letter:")
    if ip in str1 and ip not in str2:
       l=re.finditer(ip,str1)
       l=[i.start() for i in l]
       for i in l:
         str2[i]=ip
       temp=""
       for i in str2:
         temp+=i
       print(temp,end='            ')
       print('#'*n1+"~~>  life "+" left")
    else:
        print("Oops!!Try again...",end='            ')
        n1-=1
        print('#'*n1+"~~>  life "+" left")
    if temp==str1:
        print("Congrats!!You Won the Game:).....")
        break
if n1==0:
  print("Out of moves.....:)")




