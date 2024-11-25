#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX], rear = -1, front = -1;

void insertrear();
void deleterear();
void deletefront();
void insertfront();
void display();
bool isfull();
bool isempty();

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Insert from Rear\n");
        printf("2. Insert from Front\n");
        printf("3. Delete from Rear\n");
        printf("4. Delete from Front\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insertrear();
                break;
            case 2:
                insertfront();
                break;
            case 3:
                deleterear();
                break;
            case 4:
                deletefront();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 6);
    return 0;
}

bool isfull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

bool isempty() {
    return front == -1;
}

void insertrear() {
    int a;
    if(isfull()) {
        printf("Queue is full\n");
        return;
    }
    
    printf("Enter Element: ");
    scanf("%d", &a);
    
    if(front == -1) {
        front = rear = 0;
    }
    else if(rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = a;
    printf("Element inserted successfully\n");
}

void deletefront() {
    if(isempty()) {
        printf("Queue Empty\n");
        return;
    }
    
    int value = queue[front];
    
    if(front == rear) {
        front = rear = -1;
    }
    else if(front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
    printf("The deleted item is: %d\n", value);
}

void deleterear() {
    if(isempty()) {
        printf("Queue Empty\n");
        return;
    }
    
    int value = queue[rear];
    
    if(front == rear) {
        front = rear = -1;
    }
    else if(rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
    printf("The deleted item is: %d\n", value);
}

void insertfront() {
    int x;
    if(isfull()) {
        printf("Queue is full\n");
        return;
    }
    
    printf("Enter the element: ");
    scanf("%d", &x);
    
    if(front == -1) {
        front = rear = 0;
    }
    else if(front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }
    queue[front] = x;
    printf("Element inserted successfully\n");
}

void display() {
    if(isempty()) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements: ");
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}