#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
};
void push(struct node ** head_ref,int new_data){
 printf("hoii"); 
struct node *new_node=(struct node *)malloc(sizeof(struct node));
 struct node *temp=*head_ref;
 new_node->data=new_data;
 new_node->next=NULL;
 if(*head_ref==NULL){
   *head_ref=new_node;
    return;
 }
 while(temp->next!=NULL){
   temp=temp->next;
 }
 temp->next=new_node;
 
}
void print(struct node *head_ref){
  struct node * temp=head_ref;
  while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("NULL");
}
int main(){
  printf("hoii");
 struct node *head=NULL;
 printf("hoii");
 push(&head,3);
 push(&head,5);
 print(head);
 return 0;
}
