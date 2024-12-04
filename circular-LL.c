#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int nodecount=0;

struct node *createnode(int data){
    struct node *newnode = malloc(sizeof(struct node));

    newnode->data=data; 
    newnode->next=NULL;

    return newnode;
}

void insertfront(struct node **head,int data){
    if((*head)==NULL){
        *head = createnode(data);
        (*head)->next = (*head);
        nodecount++;
        return;
    }
    struct node *temp = *head, *newnode=createnode(data);
    while(temp->next!=(*head)){
        temp=temp->next;
    }
    newnode->next=(*head);
    (*head)=newnode;
    temp->next=(*head);
    nodecount++;
}

void insertend(struct node **head,int data){
    if(head==NULL){
        insertfront(head,data);
        return;
    }
    struct node *newnode=createnode(data), *temp=(*head);
    
    do{
        temp=temp->next;
    }while(temp != (*head));

    temp->next=newnode;
    newnode->next=(*head);
    nodecount++;
}

void insertspecific(struct node **head,int data,int pos){
    if((*head)==NULL || pos==1){
        insertfront(head,data);
        return;
    }
    else if(pos==nodecount){
        insertend(head,data);
    }
    else if(pos>nodecount){
        printf("invalid position.\n");
    }
    else{
        int i=1;

        struct node *temp=(*head), *prev=NULL, *newnode=createnode(data);
        while(i<pos-1){
            prev=temp;
            temp=temp->next;
        }
        prev->next=newnode;
        newnode->next=temp;

    }

    
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    
    printf("The circular linked list is:\n");
    do {
        printf("%d", temp->data);
        temp = temp->next;
        
        if (temp != head) {
            printf(" -> ");
        }
    } while (temp != head);
    
    printf("\n");
}

void main(){
    struct node *head = NULL;
    insertfront(&head,1);
    insertend(&head,2);
    insertfront(&head,3);

    insertspecific(&head,4,2);

    display(head);
}
    
