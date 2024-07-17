#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

double calculate_power_dbm(int *sig_volt, int size);


int main() {
    int sig_volt[160];
	//voltage dc 3300 mV
	for(int i=0; i<160;i++){
		sig_volt[i]=3300;		
	}
    double power_dbm = calculate_power_dbm(sig_volt, 160);
    printf("power dbm of 3.3 vdc : %f dBm\n",power_dbm);

	//voltage dc 0000 mV
    for(int i=0; i<160;i++){
		sig_volt[i]=1;		
	}
    double power_dbm1 = calculate_power_dbm(sig_volt, 160);
    printf("power dbm of 0.001 vdc : %f dBm\n",power_dbm1);

   return 0;
}
/*
Result:
power dbm of 3.3 vdc : 23.380579 dBm
power dbm of 0.001 vdc : -46.989700 dBm
*/

/*
brief: calculate voltage dc to power dBm
param sig_volt: pointer voltage data
param size: length data
return: power data in dBm
*/
double calculate_power_dbm(int *sig_volt, int size){
	double sum_volt = 0;
	for(int i=0; i<size;i++){
		sum_volt += (((double)sig_volt[i]/1000.)*((double)sig_volt[i]/1000.));
		
	}

	/*convert to Vrms*/
	double vrms = sqrt(sum_volt/(double)size);
	double form1 = 30+(20*log10(vrms/sqrt(50)));
	return form1;
}