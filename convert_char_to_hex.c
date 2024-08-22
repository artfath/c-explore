#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

void convert_char_hex(char * msg);


int main() {
    char msg[] = { 0xA1, 0xBC};
    convert_char_hex(msg);

    return 0;
}
/*
Result:
data power 40.567000 : 0xED15
data hex 0xED15, power 40.566949
data power -12.500000 : 0x0AAA
data hex 0x0AAA, power -12.500572
*/

/*
brief: convert double to hex
param num: integer number
return: value array, array 0 MSB, array 1 LSB
*/
void convert_char_hex(char * msg){
	uint8_t hex_digits[] = "0123456789ABCDEF";
	uint8_t hex[4]={0};
	int i=0;
    int n=0;
		// for(int n=0;n<len;n++){
        while(*msg){
            i+=n;
			hex[i] = hex_digits[(*msg >> 4) & 0x0F];
            i++;
            hex[i] = hex_digits[(*msg & 0x0F)];
			msg++;
            n++;
		}

    printf("data hex 0x%c%c%c%c",hex[0],hex[1],hex[2],hex[3]);
}