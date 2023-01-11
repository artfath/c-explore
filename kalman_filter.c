/*
Average Number with value appear frequently
*/
#include <stdio.h>
#include <math.h>

double Kalman_Filter(double *arr, int n);
double Alpha_Beta(double *arr, int n);
double Average(double* arr, int n);
double Variance(double* arr, int n);

int main()
{
    double arr[] = { 

1255,
1443,
1392,
1075,
1368,
1413,
1468,
1534,
893,
1402,
1397,
1417,
1414,
1469,
1407,
1939,
1491,
1333,
1272,
1252,
1143,
1508,
1439,
1368,
1029,
1040,
1390,
1374,
1541,
1341,
};
    int n = sizeof(arr) / sizeof(arr[0]);
    // printf("%d\n", n);
    // Standard_Deviation(arr,n);
    
    printf("alpa_beta: %f\n", Alpha_Beta(arr,n));
    printf("kalman_filter: %f\n", Kalman_Filter(arr,n));
    return 0;
}

double Alpha_Beta(double *arr, int n){
    double value = Average(arr,n);
    for(int x=0;x<n;x++){
        //Dynamic model
        value = value + ((arr[x]-value)/(x+1));
    }
    return value;

}
double Kalman_Filter(double *arr, int n){
    double value = Average(arr,n);
    double uncertain = 0;
    double gain = 0;
    double var = Variance(arr,n);
    double var_measure=100; //estimation variance measurement
    for(int x=0;x<n;x++){
        //Kalman Gain
        var=(var/(var+var_measure));
        //estimation current state
        value = value +(var*(arr[x]-value));
        //estimate uncertanty
        var = (1-gain)*var;
    }
    return value;

}

double Average(double* arr, int n){
    double value = 0;
    for(int c=0;c<n;c++){
        value +=arr[c];
    }
    value/=n;
    return value;
}

double Variance(double* arr, int n){
    double value = 0;
    double meanVal[100]={0};
    double mean = Average(arr,n);
    for(int c=0;c<n;c++){
        meanVal[c]=arr[c]-mean;
        meanVal[c]=meanVal[c]*meanVal[c];
        value = value + meanVal[c];
    }
    value/=n;
    // value = sqrt(value);
    return value;
}