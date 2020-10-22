class stack:
    def __init__(self):
        self.stack=[]
        self.top=-1
        self.precedence={'+':1,'-':1,'*':2,'/':2,'^':3}
    def push(self,val):
        self.stack.append(val)
        self.top+=1
    def popstack(self):
        if self.top!=-1:
            a=self.stack.pop()
            self.top-=1
            return a
        else:
            return 0
    def isempty(self):
        if self.top==-1:
            return True
        else:
            return False
    def reverse(self,str1):
        s=""
        for i in str1:
            self.push(i)
        while self.top!=-1:
            s+=str(self.popstack())
        return s
    def palindrome(self,str1):
        s=self.reverse(str1)
        if s==str1:
            return True
        else:
            return False
    def isoperand(self,s):
        s=ord(s)
        if (s>=65 and s<=90) or (s>=97 and s<=122):
            return True
            
        else:
            return False
    def notgreater(self,s):
        try:
            topstack=self.precedence[self.stack[self.top]]
            org=self.precedence[s]
            if topstack>org:
                return True
            else:
                return False
        except KeyError:
            return False

    def conversion(self,str1):
        s=""
        for i in str1:
            if self.isoperand(i):
                s+=i
                print(s)
            else:
                if i=='(':
                    self.push(i)
                elif i==')':
                    while not self.isempty() and self.stack[self.top]!='(':
                        s+=str(self.popstack())
                    self.popstack()
                else:
                    while not self.isempty() and self.notgreater(i):
                        s+=str(self.popstack())
                    self.push(i)
        while not self.isempty():
            s+=str(self.popstack())
        return s
    def balancing(self,str1):
        for i in str1:
            if i=='(' or i=='{' or i=='[':
                self.push(i)
            else:
                if i==')':
                    a=self.popstack()
                    if a!='(':
                        return False
                elif i=='}':
                    a=self.popstack()
                    if a!='{':
                        return False
                elif i==']':
                    a=self.popstack()
                    if a!='[':
                        return False
        if not self.isempty():
            return False
        return True                   



obj=stack()
if obj.balancing('[()(({{}}))()]'):
    print("balanced")
else:
    print("not balanced")
