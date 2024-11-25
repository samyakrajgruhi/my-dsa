#include<stdio.h>

void printarray(int*A ,int n){
  int i;
  printf("  Array is : { ");

  for(i=0;i<n;i++){
    printf("%d ",A[i]);
  }

  printf("}");
  printf("\n");
}

void merge(int A[], int mid, int low ,int high){
  int i,j,k,B[100];
  i=low;
  j=mid+1;
  k=low;

  while(i<=mid&&j<=high){
    if(A[i]<A[j]){
      B[k]=A[i];
      i++;
      k++;
    }

    else{
      B[k]=A[j];
      j++;
      k++;
    }
  }

  while(i<=mid){
    B[k]=A[i];
    k++;
    i++;
  }

  while(j<=high){
    B[k]=A[j];
    k++;
    j++;
  }

  for(i=low;i<=high;i++){
    A[i]=B[i];
  }
}

void mergesort(int A[],int low , int high){
  int mid;
  if(low<high){
    mid=(low+high)/2;
    mergesort(A,low,mid);
    mergesort(A,mid+1,high);
    merge(A,mid,low,high);
  }
}

void main(){
  int A[]={9,1,14,4,15,4,6};
  int n=7;

  printarray(A,n);
  printf("\n");
  mergesort(A,0,6);
  printarray(A,n);
}