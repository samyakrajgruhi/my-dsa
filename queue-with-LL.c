#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *latest = NULL;

struct node *createnode(int data){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    return newnode;
}

void enque(struct node **front,int data){
    if(*front==NULL){
        *front = createnode(data);
        latest = *front;
        return;
    }
    struct node *temp=(*front);
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = createnode(data);

    latest = temp->next;
}

void deque(struct node **front){
    struct node *temp = (*front);
    *front = (*front)->next;
    printf("Removed Element : | %d |\n",temp->data);

}

void display(struct node *front){
    if(front==NULL){
        printf("The queue is Empty.\n");
        return;
    }
    struct node *temp=front;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL){
            printf(" - ");
        }

        temp=temp->next;
    }
    printf("\n");
}

void  peek(struct node *latest){
    printf("latest value is : %d\n",latest->data);
}

void main(){
    struct node *front=NULL;

    enque(&front,1);
    enque(&front,2);
    enque(&front,3);
    enque(&front,4);

    peek(latest);

    display(front);

    deque(&front);
    display(front);

    deque(&front);
    display(front);

    deque(&front);
    display(front);

    deque(&front);
    display(front);

}