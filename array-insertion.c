#include<stdio.h>
#include<stdlib.h>

int range;

void printarray(int array[]){
    for(int i=0;i<range;i++){
        printf("%d ",array[i]);
    }
}

void insertfront(int array[]){
    int item;
    printf("\nEnter the element you want to insert at beginning :");
    scanf("%d",&item);
    range++;

    for(int i=range;i>0;i--){
        array[i]=array[i-1];
    }
    array[0]=item;

    printf("\nPrinting the array after inserting :");
    printarray(array);
}

void insertend(int array[]){
    int item;
    printf("\nEnter the element you want to insert at the end :");
    scanf("%d",&item);
    array[range]=item;
    range++;
    printarray(array);
}

void insertspecific(int array[]){
    int item,pos;
    
    
    printf("\nEnter the element you want to insert :");
    scanf("%d",&item);
    printf("Enter the position :");
    scanf("%d",&pos);
    if(pos>range){
        printf("Invalid position.");
        return;
    }
    range++;

    for(int i=range;i>pos-1;i--){
        array[i]=array[i-1];
    }

    array[pos]=item;
    printarray(array);
}



void main(){
    int array[20];

    printf("Enter the number of elements you want to enter[<20] :");
    scanf("%d",&range);

    printf("\nEnter the elements :\n");
    for(int i=0;i<range;i++){
        scanf("%d",&array[i]);
    }
    printf("\nPrinting the array :");
    printarray(array);

    insertfront(array);
    insertfront(array);
    insertend(array);
    
    insertspecific(array);



}