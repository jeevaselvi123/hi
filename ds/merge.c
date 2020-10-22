#include<stdio.h>
#include<stdlib.h>
struct node{
 int val;
 struct node *next;
};
void insert(struct node **head_ref,int data){
 struct node *newnode=(struct node*)malloc(sizeof(struct node));
 newnode->val=data;
 newnode->next=NULL;
 struct node * temp=*head_ref;
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
 struct node * newnode=(struct node*)malloc(sizeof(struct node));
 newnode->val=data;
 newnode->next=*head_ref;
 *head_ref=newnode;
 return;
}
void sort(struct node *head){
 struct node *ptr;
 int temp;
 struct node *lptr=NULL;
 int a;
  if(head==NULL){
      return;
   }
 do{
   a=0;
   ptr=head;
   while(ptr->next!=lptr){
     if(ptr->val>ptr->next->val){
        temp=ptr->val;
        ptr->val=ptr->next->val;
        ptr->next->val=temp;
        a=1;
    }
    ptr=ptr->next;
   }
  lptr=ptr;
 }while(a==1);
} 
void merge(struct node *head,struct node *head1,struct node *head2){
 struct node * temp=head;
 struct node * temp1=head1;
 sort(temp);
 sort(temp1);
 while(temp!=NULL && temp1!=NULL){
  if(temp->val>temp1->val){
    insert(&head2,temp1->val);
    temp1=temp1->next;
  }
  else if(temp->val<temp1->val){
   insert(&head2,temp->val);
   temp=temp->next;
  }
  else{
    insert(&head2,temp->val);
    temp=temp->next;
    temp1=temp1->next;
   }
 }
 while(temp!=NULL){
  insert(&head2,temp->val);
  temp=temp->next;
 }
 while(temp1!=NULL){
  insert(&head2,temp1->val);
  temp1=temp1->next;
 }
 print(head2);
}
void print(struct node *head){
 struct node * temp=head;
 while(temp!=NULL){
  printf("%d->",temp->val);
  temp=temp->next;
 }
 printf("NULL\n");
}
int main(){

 struct node *head=NULL;
 struct node *head1=NULL;
 struct node *head2=NULL;
 insert(&head,2);
 insert(&head,3);
 insert(&head,4);
 insert(&head1,6);
 insert(&head1,5);
 insert(&head1,2);
 insertfirst(&head,1);
 print(head);
  print(head1);
 merge(head,head1,head2);
}
