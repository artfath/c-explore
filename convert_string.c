/*
this string converter from number.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *convert(int num);
char *convert_double(double num, int fr);

int main() {
    
    printf("%s\n",convert(4903.4));
    printf("%s",convert_double(4903.44567,4));
    return 0;
}

/*
brief: convert integer number to string
param num: integer number
return: string value
*/
char *convert(int num){
    int digit = floor(log10(abs(num))) + 1;
    char *data_serial= malloc(digit);
    sprintf(data_serial, "%d", num);
    return data_serial;
}

/*
brief: convert floating number to string
param num: floating number
param fr: fraction digits
return: string value
*/
char *convert_double(double num, int fr){
    int digit = floor(log10(abs(num))) + 1;
    char *data_serial= malloc(10);
    gcvt(num, digit + fr , data_serial);
    return data_serial;
}

