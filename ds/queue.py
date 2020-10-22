class queue:
    def __init__(self,s):
        self.queue=[None]*s
        self.front=-1
        self.rear=-1
        self.size=0
        self.capacity=s
    def qempty(self):
        if self.size==0:
            return True
        else:
            return False
    def qfull(self):
        if self.size==self.capacity:
            return True
        else:
            return False
    def enqueue(self,val):
        if self.qfull():
            print("Queue is full!!")
        else:
            if self.qempty():
                self.front+=1
                self.rear+=1
            else:
                self.rear+=1
            self.size+=1
            self.rear=self.rear%self.capacity
            self.queue[self.rear]=val
    def dequeue(self):
        if self.qempty():
            print("Queue is empty!!")
        else:
            print("Dequed value is {0}".format(self.queue[self.front]))
            self.queue[self.front]=None
            if self.front==self.rear:
                self.front=-1
                self.rear=-1
            else:
                self.front+=1
            self.front=self.front%self.capacity
            self.size-=1
obj=queue(5)
print(obj.capacity)
obj.enqueue(20)
obj.enqueue(60)
obj.enqueue(50)
obj.enqueue(40)
obj.enqueue(30)
print(obj.queue)
obj.dequeue()
print(obj.queue)
obj.enqueue(10)
print(obj.queue)
obj.dequeue()
obj.dequeue()
obj.dequeue()
obj.dequeue()
obj.dequeue()
obj.dequeue()
obj.dequeue()
obj.enqueue(32)
print(obj.queue)
