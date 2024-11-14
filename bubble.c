#include<stdio.h>

void swap(int *array,int i,int j){
    int temp=array[i];
    array[i]=array[j];
    array[j]=temp;
}
void bubblesort(int array[],int n){
    int i;
    int j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                swap(array,j,j+1);
            }   
        }
    }
}
void main(){
    int number,i=0;
    printf("enter range:\n");
    scanf("%d",&number);
    int a[number];
    printf("enter elements:\n");
    for(i=0;i<number;i++){
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<number;i++){
        printf("%d ",a[i]);
    }
    bubblesort(a,number);
    printf("\n");
    for(i=0;i<number;i++){
        printf("%d ",a[i]);
    }
}

