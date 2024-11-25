#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int count=0;

struct node* create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insertfront(struct node** head,int data){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp = *head;
    newnode->data = data;
    newnode->next=temp;
    *head = newnode;
    count++;
}

void insertend(struct node* head, int data){
    
    struct node *temp;
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    temp = head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newnode;
    count++;

}

void insertspecific(struct node* head,int data,int pos){

    if(pos>count){
        return;
    }
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    struct node *temp=head;
    int i=1;

    while(i<pos-1){
        temp=temp->next;
        i++;
    }

    newnode->next=temp->next;
    temp->next=newnode;
    count++;
}

void display(struct node* head){
    struct node* currentnode = head;
    while(currentnode!=0){
        printf("%d", currentnode->data);
        if (currentnode->next != NULL) {
            printf(" -> ");
        }
        currentnode=currentnode->next;
    }
}




void main(){
    struct node *head = NULL;
    int choice=0,data;

    while(choice!=5){
        printf("\n1.Insert at Front.");
        printf("\n2.Insert at End.");
        printf("\n3.Insert at Specific.");
        printf("\n4.Display");
        printf("\n5.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);

        if(choice==1){
            printf("Enter Data :");
            scanf("%d",&data);

            insertfront(&head,data);
        }
        else if(choice==2){
            printf("Enter Data :");
            scanf("%d",&data);
            if(head==0){
                insertfront(&head,data);
            }   
            else{
                insertend(head,data);
            }
            
        }
        else if(choice==3){
            int pos;
            printf("Enter Data :");
            scanf("%d",&data);
            printf("Enter Position :");
            scanf("%d",&pos);

            insertspecific(head,data,pos);
        }
        else if(choice==4){
            display(head);
        }
        else{
            break;
        }
    }
}