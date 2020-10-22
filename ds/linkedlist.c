#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
};
void push(struct node**head_ref,int new_data){
 struct node *new_node=(struct node *)malloc(sizeof(struct node));
 new_node->data=new_data;
 new_node->next=(*head_ref);
 (*head_ref)=new_node;

}

void append(struct node **head_ref,int new_data){
 struct node* new_node=(struct node*)malloc(sizeof(struct node));
 struct node *last=*head_ref;
 new_node->data=new_data;
 new_node->next=NULL;
 if(*head_ref==NULL){
   *head_ref=new_node;
    return;
  }
 while(last->next!=NULL)
   last=last->next;
 last->next=new_node;
 return;

}

void print(struct node*temp){
  while(temp!=NULL){
   printf("%d->",temp->data);
   temp=temp->next;
  }
}


int main(){
struct node *head=NULL;
append(&head,2);
append(&head,3);
push(&head,7);
print(head);




}
