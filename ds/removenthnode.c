#include<stdio.h>
#include<stdlib.h>
struct node{
 int val;
 struct node *next;
};
void insert(struct node **head_ref,int newdata){
 struct node *newnode=(struct node *)malloc(sizeof(struct node));
 newnode->val=newdata;
 newnode->next=NULL;
 struct node *temp=*head_ref;
 if(*head_ref==NULL){
  *head_ref=newnode;
   return;
 }
 while(temp->next!=NULL)
 {
   temp=temp->next;
  }
 temp->next=newnode;
 return;
}
void print(struct node *head){
 struct node* temp=head;
 while(temp!=NULL){
  printf("%d->",temp->val);
  temp=temp->next;
 }
 printf("NULL");
}
void removenode(struct node **head_ref,int position){
 struct node *temp=*head_ref;
 struct node *prev;
 int count=1,t=0;
 while(temp->next!=NULL){
  temp=temp->next;
  count++;
 }
 temp=*head_ref;
 while(temp!=NULL&&t<(count-position)){
  prev=temp;
  temp=temp->next;
  t++;
 }
 prev->next=temp->next;
 free(temp);
 return;

}
int main(){
 struct node *head=NULL;
 insert(&head,1);
 insert(&head,2);
 insert(&head,3);
 insert(&head,4);
 insert(&head,5);
 print(head);
 removenode(&head,4);
 printf("\nAfter remove:");
 print(head);
}
