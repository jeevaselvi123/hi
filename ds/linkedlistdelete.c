#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
};
void bubblesort(struct node *head){
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
void insert(struct node **head_ref,int new_data){
 struct node* new_node=(struct node *)malloc(sizeof(struct node));
 struct node *last=*head_ref;
 new_node->data=new_data;
 new_node->next=NULL;
 if(*head_ref==NULL){
  *head_ref=new_node;
   return;
  }
 while(last->next!=NULL){
  last=last->next;
 }
 last->next=new_node;
 
 return;

}
void insertfirst(struct node **head_ref,int new_data){
 struct node * new_node=(struct node *)malloc(sizeof(struct node));
 new_node->data=new_data;
 new_node->next=(* head_ref);
 (*head_ref)=new_node;
}

int count(struct node* head_ref){
 struct node * temp=head_ref;
 int count=0;
 while(temp!=NULL){
   count++;
   temp=temp->next;  
 }
 return count;
}

void delete(struct node **head_ref,int del_data){
 struct node *temp=*head_ref;
 struct node *prev;
 int count=0;
 if(count==del_data){
  *head_ref=temp->next;
   free(temp);
   return;
 }
 while(temp!=NULL && count!=del_data){
  count++;
  prev=temp;
  temp=temp->next;
 }
 prev->next=temp->next;
 free(temp);
}

void print(struct node *temp){
 while(temp!=NULL){
   printf("%d->",temp->data);
   temp=temp->next;
 }
 printf("NULL\n");
}
int main(){
 struct node* head=NULL;
 insert(&head,2);
 insert(&head,3);
 insert(&head,7);
 insertfirst(&head,9);
  insert(&head,5);
 print(head);
 int a=count(head);
 printf("before delete No. of Elmnts in linked list:%d\n",count(head));
 delete(&head,3);
 printf("after delete No. of Elmnts in linked list:%d\n",count(head));
  print(head);
 bubblesort(head);
 print(head);
}
