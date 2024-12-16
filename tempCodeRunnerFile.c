#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *createnode(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insertfront(struct node **head,int data){
    struct node *newnode=createnode(data);
    if(*head==NULL){
        *head=newnode;
        newnode->next=*head;

    }
    else{
        newnode->next= *head;
        *head=newnode;
    }
}

void insertend(struct node *head,int data){
    struct node *newnode=createnode(data);
    struct node *temp=head;
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void insertspecific(struct node *head,int data){
    int position;
    printf("enter position:\n");
    scanf("%d",&position);
    struct node *temp=head;
    struct node *newnode=createnode(data);
    int i=1;
    while(i<position-1){
        temp=temp->next;
        i++;
        
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void printlist(struct node *head){
    struct node *temp=head;
    while(temp->next!=head){
        printf("%d\n",temp->data);
        temp=temp->next;
        
    }
    printf("\n");
}
/// 4,10,6,3,15,1,34,22,45
void main(){
    struct node *head=NULL;
    head=createnode(15);
    insertfront(&head,3);
    insertfront(&head,6);
    insertfront(&head,4);
    insertspecific(head,10);
    insertend(head,1);
    insertend(head,34);
    insertend(head,22);
    insertend(head,45);
    printlist(head);
}