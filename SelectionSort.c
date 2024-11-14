#include<stdio.h>
void selectionsort(int array[],int size){
    int step,i,temp,minindex;
    for(step=0;step<size-1;step++){
        minindex=step;
        for(i=step+1;i<size;i++){
            if(array[i]<array[minindex]){
                minindex=i;
            }
        }
        temp=array[minindex];
        array[minindex]=array[step];
        array[step]=temp;
    }
}
void printarray(int array[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d\n",array[i]);
    }
}
int main(){
    int data[]={29,10,14,37,13};
    int size=sizeof(data)/sizeof(data[0]);
    printf("\nUnsorted array\n");
    printarray(data,size);
    selectionsort(data,size);
    printf("\nSorted array\n");
    printarray(data,size);
    return 0;
}