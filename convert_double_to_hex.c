#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

uint8_t *convert_double_hex(double num);
double convert_hex_double(uint8_t * hex);

int main() {
    double power = 40.567, min_power = -12.5;
    uint8_t * hex_value = malloc(2*sizeof(uint8_t));
    hex_value = convert_double_hex(power);
    printf("data power %f : 0x%02X%02X\n",power, hex_value[0],hex_value[1]);
    power = convert_hex_double(hex_value);
    printf("data hex 0x%02X%02X, power %f\n",hex_value[0],hex_value[1],power);

    hex_value = convert_double_hex(min_power);
    printf("data power %f : 0x%02X%02X\n",min_power, hex_value[0],hex_value[1]);
    min_power = convert_hex_double(hex_value);
    printf("data hex 0x%02X%02X, power %f\n",hex_value[0],hex_value[1],min_power);
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
Eq:
    hex_value[15:0] = ((double_value +15) x 65335) / 60
    upper limit : 60-15 = 45
    lower limit : -15
param num: integer number
return: value array, array 0 MSB, array 1 LSB
*/
uint8_t *convert_double_hex(double num){
    uint8_t *data_hex = malloc(2*sizeof(uint8_t));
    double num_eq = ((num+15)*65535)/60;

    uint16_t num_bit =(uint16_t) num_eq;
    data_hex[0]= (uint8_t)(num_bit>>8);
    data_hex[1]= (uint8_t)(num_bit & 0xFF);
    return data_hex;
}

/*
brief: convert hex to double
Eq:
    double_value = (60 x (hex[15:0]/65335))-15
    upper limit : 60-15 = 45
    lower limit : -15
param hex: 2 array value
return: double value
*/
double convert_hex_double(uint8_t * hex){
    double num_eq;
    uint16_t num_bit;
    num_bit = (uint16_t)(hex[0]<<8);
    num_bit = (uint16_t)(num_bit | hex[1]);

    num_eq = (((double)num_bit/65535.)*60)-15;
    
    return num_eq;
}