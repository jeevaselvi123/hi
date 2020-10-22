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
def push(val):
    q2.enqueue(val)
    print(q1.queue,q2.queue)
    while q1.size!=0:
        q2.enqueue(q1.dequeue())
    q1.queue,q2.queue=q2.queue,q1.queue
def pop():
    print(q1.dequeue())
q1=queue(5)
q2=queue(5)
push(4)
push(3)
push(7)
print(q1.queue)
pop()
pop()