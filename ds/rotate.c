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

void counterrotate(struct node **head_ref,int k){
 struct node *current=*head_ref; 
 struct node *temp;
 int count=1;
 while(current->next!=NULL&&count<k){
   current=current->next;
   count++;
  }
 temp=current;
 while(current->next!=NULL){
  current=current->next;
 }
 current->next=*head_ref;
 *head_ref=temp->next;
 temp->next=NULL;
 return;
}
 
void clockrotate(struct node **head_ref,int k){
 struct node *current=*head_ref; 
 struct node *temp;
 int count=1;
 while(current->next!=NULL){
   current=current->next;
   count++;
  }
 printf("%d\n",count);
 current=*head_ref;
 int count1=1;
 while (current->next!=NULL&&count1<(count-k)){
  current=current->next;
  count1++;
 }
 temp=current;
 while(current->next!=NULL){
  current=current->next;
 }
 current->next=*head_ref;
 *head_ref=temp->next;
 temp->next=NULL;
 return;
}
struct node * nrotate(struct node *head,int k){
  struct node *current=head;
  struct node *next=NULL;
  struct node *prev=NULL;
  int count=0;
  while(current!=NULL&&count<k){
   next=current->next;
   current->next=prev;
   prev=current;
   current=next;
   count++;
  }
 if(head!=NULL){
  head->next=current;
 }
 count=0;
 while(count<k-1&&current!=NULL){
  current=current->next;
  count++;
 }
 if(current!=NULL){
  current->next=nrotate(current->next,k);
 }
 return prev;
 
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
  //clockrotate(&head,3);
 //print(&head);
 //counterrotate(&head,3);
  //print(&head);
  head=nrotate(head,2);
  print(&head);
}
