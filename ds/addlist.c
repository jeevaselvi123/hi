#include<stdio.h>
#include<stdlib.h>
struct node{
 int val;
 struct node * next;
};
void insert(struct node **head_ref,int newdata){
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  struct node *temp=*head_ref;
  newnode->val=newdata;
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
void print(struct node *head){
 struct node *temp=head;
 while(temp!=NULL){
  printf("%d->",temp->val);
  temp=temp->next;
 }
 printf("NULL");
}
void addlist(struct node *head1,struct node *head2){
 int temp;
  struct node *head3=NULL;
 struct node *ptr1=head1;
 struct node *ptr2=head2;
 while(ptr1!=NULL&&ptr2!=NULL){
  temp=ptr1->val+ptr2->val;
  insert(&head3,temp);
  ptr1=ptr1->next;
  ptr2=ptr2->next;
 }
 print(head3);
}
int main(){
 struct node *head=NULL;
 struct node *head1=NULL;
 insert(&head,2);
 insert(&head,3);
 insert(&head,4);
 insert(&head1,6);
 insert(&head1,2);
 insert(&head1,5);
 print(head);
 printf("\n");
 print(head1);
 addlist(head,head1);
}
