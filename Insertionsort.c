#include <stdio.h>

void main()
{
    int a[6]={5,2,7,4,3,1};
    int i,j,k;

    printf("\nPrinting the un-sorted array.\n");
    for(i=0;i<6;i++){
        printf("a[%d]=%d ",i,a[i]);
    }
    for(int s=0;s<6;s++){
        for(i=0;i<6;i++){
            j=i+1;
            if(a[i]>a[j]){
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
            
            else{
                continue;
            }

        printf("\n\nPrinting the passes array.\n\n");
        for(int f=0;f<6;f++){
           printf("a[%d]=%d ",f,a[f]);
        } 
        }
    }

    printf("\nPrinting the sorted array.\n\n");
    for(i=0;i<6;i++){
        printf("a[%d]=%d ",i,a[i]);
    }
}