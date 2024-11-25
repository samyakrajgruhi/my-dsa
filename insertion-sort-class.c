#include <stdio.h>

void insertionSort(int arr[], int N){
    for(int i=1; i<N; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
    }
}

void printArray(int arr[], int N){
    for(int i=0; i<N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main(){
    int arr[] = {12,11,13,5,6};
    int N = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted Array - ");
    printArray(arr, N);
    printf("\n");

    insertionSort(arr, N);
    printf("Sorted Array - ");
    printArray(arr,N);
}