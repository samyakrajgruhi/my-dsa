#include <stdio.h>
int MAXSIZE = 8;
int stack[8];
int top = -1;

int isfull(){
    if(top == MAXSIZE){
        return 1;
    }
    else{
        return 0;
    }
}

int push(int data){
    if(!isfull()){
        top = top + 1;
        stack[top] = data;
    }
    else{
        printf("Could not insert data, Stack is full.\n");
    }
}

void pop(){
    top = top - 1;
}

void main(){
    int i;
    push(40);
    push(20);
    push(30);
    push(10);
    pop();
    printf("Stack elements are: \n");
    for(i=0; i<top+1; i++){
        printf("%d\n", stack[i]);
    }
}