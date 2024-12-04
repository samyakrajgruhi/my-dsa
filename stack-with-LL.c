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

void push(struct node **top,int data){
    struct node *newnode = createnode(data);
    newnode->next=(*top);
    (*top)=newnode;
}

void pop(struct node **top){
    struct node *temp = *top;
    *top = (*top)->next;
    printf("Popped node is : | %d |\n",temp->data);

}

void printlist(struct node *top){
    struct node *temp=top;
    printf("The Stack is :\n");
    while(temp!=NULL){
        printf("| %d |",temp->data);
        if(top->next!=NULL){
            printf("\n");
        }
        temp=temp->next;
    }
}

void main(){
    struct node *top=NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);
    push(&top,4);
    push(&top,5);

    printlist(top);

    pop(&top);
    pop(&top);
    
    printlist(top);

}

