class stack:
    def __init__(self):
        self.stack=[]
        self.top=-1
    def push(self,val):
        self.top+=1
        self.stack.append(val)
    def popstack(self):
        if self.top==-1:
            return 0
        else:
            a=self.stack.pop()
            self.top-=1
            return a
    
def enqueue(val):
  s1.push(val)
def dequeue():
    while s1.top!=-1:
        s2.push(s1.popstack())
    print("dequeued value:",s2.popstack())  
    

s1=stack()
s2=stack()
enqueue(10)
enqueue(20)
enqueue(30)
enqueue(40)
print(s1.stack)
dequeue()
dequeue()
print(s2.stack)