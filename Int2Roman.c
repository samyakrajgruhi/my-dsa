#include<stdio.h>
#include<math.h>
#include<string.h>

struct romans{
    const char* roman;
    int value;
};

void main(){
    char final[100]="";
    struct romans values[] = {
        {"M",1000},
        {"CM",900}, 
        {"D",500}, 
        {"CD",400}, 
        {"C",100}, 
        {"XC",90},  
        {"L",50},
        {"XL",40}, 
        {"X",10},
        {"IX",9},
        {"V",5},
        {"IV",4},
        {"I",1}
    };
    int number;
    printf("Enter a number :");
    scanf("%d",&number);

    for(int i=0;i<13;i++){
        if(number>=values[i].value){
            strcat(final,values[i].roman);
            number = number - values[i].value;
            i = -1;
           }
    }
    printf("%s",final);
}  