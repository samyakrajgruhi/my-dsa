#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct romans{
    char roman;
    int value;
};

void main(){
    struct romans values[] = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int final=0;
    char rom[10];
    gets(rom);
    int range = strlen(rom);
    int r=
    for(int i=0;i<range;i++){
        int value;
        char crom=rom[i];
        char nrom=rom[i+1];
        int cval=0,nval=0;
        for(int j=0;j<r;j++){
            if(crom==values[j].roman){
                cval+=values[j].value;
            }
            if(nval<range){
                if(nrom==values[j].roman){
                    nval+=values[j].value;
                }
            }
        }
        if(nval>cval){
            final = final - cval + nval;
            i++;
        }
        else{
            final = final + cval;
        }
    }
    printf("\n%d",final);
}