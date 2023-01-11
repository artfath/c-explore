/*
Average Number with value appear frequently
*/
#include <stdio.h>
#include <math.h>
 
double Average_Number(double* arr, double n, double range);
double Average(double* arr, double n);

int main()
{
    double arr[] = { 815,
982,
990,
852,
913,
826,
629,
927,
838,
892,
875,
826,
791,
944,
843,
884,
788,
656,
903,
790,
1026,
796,
833,
844,
889,
627,
};
    double n = sizeof(arr) / sizeof(arr[0]);
    printf("%f\n", Average_Number(arr, n, 110));
    printf("%f", Average(arr, n));
    return 0;
}

/*
brief: average value by eliminating unimportant values
param arr: value array
param n: length array value
param range: range group value
return: double averaging value
*/
double Average_Number(double* arr, double n, double range)
{
  
    double maxcount = 0;
    double val_often=0;
    int num=0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i]-range < arr[j] && arr[i]+range > arr[j]){
                count++;}
        }
 
        if (count > maxcount) {
            
            maxcount = count;
            
        }
        if(i>0){
            if(count == maxcount){
            num++;
            val_often += arr[i];
        }
        }
        
    }
    val_often /= num;
 
    return val_often;
}

/*
brief: average value
param arr: value array
param n: length array value
return: double averaging value
*/
double Average(double* arr, double n){
    double value = 0;
    for(int c=0;c<n;c++){
        value +=arr[c];
    }
    value/=n;
    return value;
}