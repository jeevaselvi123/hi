#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node * next;
};
void insert(struct node ** head_ref,int newdata){
 struct node * newnode=(struct node*)malloc(sizeof(struct node));
 struct node * temp=*head_ref;
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
void sort(struct node*head_ref){
 struct node *ptr;
 int temp,a;
 struct node *lptr=NULL;
 do{
  a=0;
  ptr=head_ref;
  while(ptr->next!=lptr){
   if(ptr->data>ptr->next->data){
      temp=ptr->data;
      ptr->data=ptr->next->data;
      ptr->next->data=temp;
      a=1;
    }
   ptr=ptr->next;
  }
  lptr=ptr;
 }while(a==1);
}
void mergeksorted(struct node *head1,struct node *head2,struct node*head){
 struct node * head3=NULL;
 struct node * temp=head1;
 struct node * temp1=head2;
 struct node *temp2=head;
 while(temp&&temp1&&temp2){
 if(temp->data>temp1->data&&temp->data>temp2->data){
   insert(&head3,temp->data);
   temp=temp->next;
 }
 else if(temp1->data>temp->data&&temp1->data>temp2->data){
   insert(&head3,temp1->data);
   temp1=temp1->next;
 }
 else if(temp2->data>temp->data&&temp2->data>temp1->data){
  insert(&head3,temp2->data);
  temp2=temp2->next;
 }
 else{
  insert(&head3,temp->data);
  temp=temp->next;
  temp1=temp1->next;
  temp2=temp2->next;
 }
 }
 while(temp!=NULL){
  insert(&head3,temp->data);
  temp=temp->next;
 }
 
 while(temp1!=NULL){
  insert(&head3,temp1->data);
  temp1=temp1->next;
 }
 
 while(temp2!=NULL){
  insert(&head3,temp2->data);
  temp2=temp2->next;
 }
 print(head3);
}
void print(struct node *head){
 struct node *temp=head;
 while(temp!=NULL){
  printf("%d->",temp->data);
  temp=temp->next;
 }
 printf("NULL");
}
int main(){
 struct node *head=NULL;
 struct node *head1=NULL;
 struct node *head2=NULL;
 insert(&head,1);
 insert(&head,2);
 insert(&head,3);
 insert(&head1,1);
 insert(&head1,2);
 insert(&head2,5);
 insert(&head2,2);
 print(head);
 printf("\n");
 print(head1);
 printf("\n");
 print(head2);
 sort(head);
 sort(head1);
 sort(head2);
 printf("After sorting: ");
 print(head);
 printf("\n");
 print(head1);
 printf("\n");
 print(head2);
 mergeksorted(head,head1,head2);
}
