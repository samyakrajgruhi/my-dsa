#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createnode(int data){
    struct node *newnode = malloc(sizeof(struct node));

    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;

    return newnode;
}

void insertfront(struct node **head,int data){
    struct node *newnode = createnode(data);
    if(*head != NULL){
        newnode->next = *head;
        (*head)->prev = newnode;
    }    
    *head = newnode;
}

void insertend(struct node **head,int data){
    if(*head==NULL){
        insertfront(head,data);
        return;
    }

    struct node *temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct node *newnode = createnode(data);
    newnode->prev=temp;
    temp->next=newnode;
}



void insertspecific(struct node **head, int data, int pos){
    if(pos==1){
        insertfront(head,data);
    }
    int i=1;
    struct node *newnode = createnode(data);
    struct node *temp=*head;

    while(i<pos-1){
        temp=temp->next;
    }

    newnode->prev = temp;
    newnode->next = temp->next;

    temp->next->prev = newnode;
    temp->next = newnode;

}

void delete(struct node **head,int data){
    if((*head)->data==data){
        struct node *temp = *head;
        (*head) = (*head)->next;
        if((*head)==NULL){
            printf("Element |%d| deleted successfully.\n",data);
            return;
        }
        (*head)->prev=NULL;
        printf("Element |%d| deleted successfully.\n",data);
        free(temp);
        return;
    }

    int i=1;
    struct node *temp=(*head), *prev=NULL;
    while(temp->data!=data){
        prev=temp;
        temp=temp->next;
    }
    if(temp->next==NULL){
        prev->next = NULL;
        printf("Element |%d| deleted successfully.\n",data);
        free(temp);
        return;
    }
    prev->next = temp->next;
    temp->next->prev = prev;
    free(temp);
    printf("Element |%d| deleted successfully.\n",data);
    return;


}

void display(struct node *head){
    struct node *temp = head;
    
    printf("The Double Ended Linked List is :\n");

    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL){
            printf(" <-> ");
        }

        temp=temp->next;

    }
    printf("\n");
}

void main(){
    struct node *head=NULL;

    insertend(&head,1);
    insertend(&head,2);
    insertfront(&head,3);
    insertspecific(&head,4,2);

    display(head);

    delete(&head,2);
    display(head);

    delete(&head,3);
    display(head);

    insertend(&head,10);
    display(head);

    delete(&head,1);
    display(head);
}