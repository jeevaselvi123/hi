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

void reverse(struct node **head_ref){
  struct node *current=*head_ref;
  struct node *prev=NULL;
  struct node *next=NULL;
  while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }
  *head_ref=prev;
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
 insert(&head,2);
 insert(&head,4);
 insert(&head,5);
 insert(&head,6);
 insert(&head,7);
 print(&head);
 reverse(&head);
 print(&head);
}
