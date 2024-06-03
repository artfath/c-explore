#include<stdio.h>
#include <stdlib.h>

int *decimal_to_binary(int dec, int *num_bit);


int main() {
    int *bit, x;
    int dec = 9;
    bit = decimal_to_binary(dec,&x);
    printf("binary of %d decimal is:\n",dec);
    for(int i=0;i<x;i++){
        printf("bit[%d] = %d\n",i,bit[i] );
    }
    printf("number bits %d",x);
}
/*
Result:
binary of 9 decimal is:
bit[0] = 1
bit[1] = 0
bit[2] = 0
bit[3] = 1
number bits 4
*/

/*
brief: convert decimal to binary
param dec: decimal value
param num_bit: number of bits binary
return: array of binary value
*/
int *decimal_to_binary(int dec, int *num_bit){
    int *bin,i=0;
    int z=dec;
    if(dec==0){
        *num_bit = 1;
        return 0;
    }
        do{
        z=z/2;
        i++;
    }  while(z > 0) ; 
    bin = malloc(sizeof(int *)*i);
    i=0;
    do{
        bin[i] = dec%2;
        dec=dec/2;
        i++;
    }  while(dec > 0) ; 
    *num_bit = i;
    return bin;
}