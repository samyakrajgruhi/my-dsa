#include<stdio.h>
#include<stdlib.h>

int count;

struct node{
    int data;
    struct node* next;
};

struct node *createnode(int data){

    struct node* newnode = malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    return newnode;
}

void insertend(struct node* head,int data){
    struct node *temp=head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = createnode(data);
    count++;
}

void insertfront(struct node **head,int data){
    struct node *newnode = createnode(data);
    newnode->next=(*head);
    *head = newnode;
    count++;
}

void insertspecific(struct node *head,int data,int pos){
    struct node *temp=head;
    struct node *newnode=createnode(data);
    int i=1;
    while(i<pos-1){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void deletion(struct node **head,int data){
    if((*head)==NULL){
        return;
    }
    if((*head)->data==data){
        (*head)=(*head)->next;
        return;
    }
    struct node *temp=(*head),*prev=NULL;
    while(temp->next->data!=data){
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

void printlist(struct node *head){
    struct node *temp=head;

    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}

void main(){
    struct node *head=NULL;
    head = createnode(1);

    insertend(head,2);
    insertend(head,3);
    insertend(head,4);

    insertfront(&head,5);
    deletion(&head,2);
    
    insertspecific(head,2,2);
    printlist(head);
}
