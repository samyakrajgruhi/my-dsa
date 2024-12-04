#include<stdio.h>
#include<stdlib.h>

void printarray(int arr[],int range){
    for(int i=0;i<range;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");
}

void bubblesort(int arr[],int range){
    for(int k=0;k<range-1;k++){
        for(int i=0;i<range-k-1;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        printf("array after %d pass :",k+1);
        printarray(arr,range);
    }
}

void main(){
    int arr[]={12,5,2,9,6,3,1,32,17,92,10,8},range;
    range=sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted Array :");
    printarray(arr,range);

    bubblesort(arr,range);

    printf("Sorted Array :");
    printarray(arr,range);
}