#include<stdio.h>
int arr[100];
int top,i,x,choice,n;
void push();
void pop();
void display();
int main(){
  top=-1;
  printf("Enter the size of array:\n");
  scanf("%d",&n);
  printf("\t\t\tSTACK OPERATIONS\n");
  do{
    printf("1.push\n2.pop\n3.display\n4.exit\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
          push();
          break;
      case 2:
          pop();
          break;
      case 3:
          display();
          break;
       case 4:
           printf("Operation terminated!!\n");
           break;
        default:
           printf("Enter the correct operation....\n");
           break;
    }
  }while(choice!=4);
}
void push(){
 if(top>=n-1){
  printf("Stack is overflow...\n");
 } 
 else{
   printf("Enter the value to be inserted...");
   scanf("%d",&x);
   top++;
   arr[top]=x;
  }
}
void pop(){
 if(top==-1){
  printf("Stack is underflow...\n");
 }
   printf("popped elmnt is:%d\n",arr[top]);
   top--;

}
void display(){
 if(top==-1){
  printf("Stack is empty\n");
 }
 printf("Elemnts in stack are..\n");
  for(i=top;i>=0;i--){
   printf("\n%d\n ",arr[i]);
  }
}
