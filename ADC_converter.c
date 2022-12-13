/*
this ADC convert adc value to voltage value.
the voltage value range 0 to 15 volt.
12 bit ADC conversion with 3.3 voltage reference.
*/
#include <stdio.h>

double converter(int adc);

int main(){
    double x = converter(1500);
    printf("%.2f",x);
    return 0;
}

/*
brief: convert 12-bit ADC to voltage value, range 0-15 volt
param num: integer number
return: string value
*/
double converter(int adc){
    double vin;
    double vout;
    vin = (3.3/4096)*adc;
    vout = (15/3.3)*vin;
    return vout;
}