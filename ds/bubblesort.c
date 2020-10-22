#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
 int data;
 struct node *next;
};
void push(struct node **head_ref,int data)
{
 struct node *newnode=(struct node*)malloc(sizeof(struct node));
 struct node * temp=*head_ref;
 newnode->data=data;
 newnode->next=NULL;
 if(*head_ref==NULL){
  *head_ref=newnode;
   return;
 }
 while(temp->next!=NULL){
  temp=temp->next; 
 }
 temp->next=newnode;
   return;
}
void insertfirst(struct node **head_ref,int data){
 struct node * newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=data;
 newnode->next=(*head_ref);
 (*head_ref)=newnode;
 return;
}
void median(struct node **head_ref){
 struct node *slow=*head_ref;
 struct node *fast=*head_ref;
 while((fast!=NULL)&&(fast->next!=NULL)){
  slow=slow->next;
  fast=fast->next->next;
 }
 printf("The median is %d",slow->data);
 return;
}
void print(struct node * head){
 while(head!=NULL){
   printf("%d->",head->data);
   head=head->next;
  }
  printf("NULL\n");
}
void alternate(struct node **head_ref){
 struct node *temp=*head_ref;
 int store;
 while(temp!=NULL&&temp->next!=NULL){
  store=temp->data;
  temp->data=temp->next->data;
  temp->next->data=store;
  temp=temp->next->next;
 }
 return;
}
void unique(struct node **head_ref){
 struct node *ptr1,*ptr2,*dup;
 ptr1=(*head_ref);
 while(ptr1!=NULL&&ptr1->next!=NULL){
   ptr2=ptr1;
   while(ptr2->next!=NULL){
      if(ptr1->data==ptr2->next->data){
        dup=ptr2->next;
        ptr2->next=ptr2->next->next;
        free(dup);
      }  
    else{
     ptr2=ptr2->next;}

  }
  ptr1=ptr1->next;
 }
}

void uniqueelmnt(struct node **head_ref){
  struct node *ptr1,*ptr2,*temp,*dup;
  int count;
  ptr1=(*head_ref);
  while(ptr1!=NULL&&ptr1->next!=NULL){
    ptr2=ptr1;
    temp=ptr1;
    count=0;
    while(ptr2->next!=NULL){
      if(ptr1->data==ptr2->next->data){
          dup=ptr2->next;
          ptr2->next=ptr2->next->next;
          free(dup);
          count=1;
      }
      else{
         ptr2=ptr2->next;
       }
    }
     if(count==1){
        ptr1=ptr1->next;
        free(temp);
     }
     else{
          ptr1=ptr1->next;
     }

  }

}
int main(){
 struct node *head=NULL;
 push(&head,3);
 insertfirst(&head,6);
 push(&head,2);
 push(&head,7);
 insertfirst(&head,2);
 push(&head,5);
  push(&head,5);
 push(&head,4);
 push(&head,7);
 print(head);
 median(&head);
 alternate(&head);
 print(head);
 unique(&head);
 print(head);
 uniqueelmnt(&head);
  print(head);
}
