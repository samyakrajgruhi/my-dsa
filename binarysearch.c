#include<stdio.h>
/* this is updated code*/
void main(){
    int range,search,limit;
    printf("Enter range of the array :\n");
    scanf("%d",&range);

    int array[range];
    printf("Enter element(s) of array :\n");
    for(int i=0;i<range;i++){
        scanf("%d",&array[i]);
    }
    printf("Enter the number you want to search :\n");
    scanf("%d",&search);

    int first=0 , middle, last=range;
    limit = range+2;
    int flag=1;
    while(flag!=limit){
        middle=(first+last)/2;
        if(array[middle]==search){
            printf("Number %d is found at position %d.",search,middle+1);
            break;
        }
        else if(search<array[middle]){
            last=middle;
        }
        else if(search>array[middle]){
            first=middle;
        }
        flag++;
    }
    if(flag==limit){
        printf("Number not found in the given array.");
    }
}