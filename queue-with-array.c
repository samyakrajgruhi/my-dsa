#include<stdio.h>
#include<stdlib.h>
#define max 20
int front=-1,rear=-1,queue[max];

int isfull(){
    if(rear==max-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(){
    if(front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(int item){
    if(isfull()){
        printf("Queue Full!!\n");
        return;
    }
    else if(isempty()){
        front=rear=0;
    }
    else{
        rear++;
    }
    queue[rear]=item;
}

void deque(){
    if(isempty()){
        printf("Queue is Empty..\n");
        return;
    }
    else{
        printf("Removed %d from the queue.\n",queue[front]);
        front=front+1;
    }
}

void show(){
    if(!isempty()){
        printf("%d\n",queue[front]);
    }
    else{
        printf("Queue is empty...\n");
    }
}

void display(){
    if(isempty()){
        printf("Queue is Empty...");
        return;
    }
    printf("Queue is : ");
    for(int i=front;i<=rear;i++){
        printf(" %d",queue[i]);
    }
    printf("\n");
}

void main(){
    int choice;
    
    do{
        printf("\n1.Enque\n");
        printf("2.Dequq\n");
        printf("3.Show\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            int item;
            case 1: 
                printf("Enter the element :");
                scanf("%d",&item);
                enque(item);
                break;
            case 2:
                deque();
                break;
            case 3:
                show();
                break;
            case 4:
                display();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice");
        }
    }while(choice!=5);
}