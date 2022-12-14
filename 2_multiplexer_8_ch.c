/*
convert number of channel to binary address of multiplexer.
this using for 2 multiplexer with selector inhibit
*/
#include <stdio.h>

void multiplexer(int num, int inh);

int main() {
    int x;
    for( x=0 ; x<16 ; x++){
        if(x<8){
            multiplexer(x, 0);
        }else{
           multiplexer(x, 1); 
        }
        
    }
    
    return 0;
}

/*
brief: convert integer number to binary
param num: integer value
param inh: inhibit
return: none
*/
void multiplexer(int num, int inh){
    //Address A, B,C
	int valuea = num & 0b0001;
	int valueb = (num & 0b0010)>>1;
	int valuec = (num & 0b0100)>>2;

    printf("%d%d%d\t",valuec,valueb,valuea);
    printf("%d\n",inh);
}