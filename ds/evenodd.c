#include<stdio.h>
#include<stdlib.h>
struct node {
 int data;
 struct node* next;
};
void insert(struct node **head_ref,int newdata){
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  struct node *temp=*head_ref;
  newnode->data=newdata;
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
void evenodd(struct node **head_ref){
 struct node *current=*head_ref;
 struct node *odd=current;
 struct node *even=current->next;
 while(current!=NULL){
   odd->next=odd->next?odd->next->next:odd->next;
   even->next=even->next?even->next->next:even->next;
 }
 while(odd->next!=NULL){
  printf("%d ",odd->data);
  odd=odd->next;
 }
 while(even->next!=NULL){
  printf("%d ",even->data);
  even=even->next;
 }
}
void print(struct node **head){
  struct node *temp=*head;
  while(temp!=NULL){
   printf("%d->",temp->data);
   temp=temp->next;
  }
  printf("NULL\n");
}

int main(){
 struct node *head=NULL;
 insert(&head,1);
 insert(&head,2);
 insert(&head,3);
 insert(&head,4);
 insert(&head,5);
 insert(&head,6);
 print(&head);
 evenodd(&head);
  
}
