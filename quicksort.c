#include<stdio.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return(i+1);
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

void printarray(int arr[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d",arr[i]);
        printf("\t");
    }
}

void main(){
    int arr[]={12,17,6,25,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("\nUnsorted array:\n");
    printarray(arr,n);
    quicksort(arr,0,n-1);
    printf("\nSorted array:\n");
    printarray(arr,n);
}