/*
concatenate two string or more with input pointer char array.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concatenate_string(char *str[], int row);

int main() {
    char *str[20];
    str[0] ="12.1 V";
    str[1] ="12.0 V";
    str[2] ="12.2 V";
    str[3] ="12.0 V";
    str[4] ="12.42 V";
    str[5] ="12.6 V";
    str[6] ="12.134 V";
    str[7] ="12.98 V";
    char *x;
    x  = concatenate_string(str,8);
    printf("%s",x);
    return 0;
}

/*
brief: convert integer number to string
param str: char array
param row: number of rows
return: string value
*/
char *concatenate_string(char *str[], int row){
    char *s;
    int len = 0;
    int *length = (int*) malloc(row * sizeof(int));
    int m=0;

    for(int f = 0; f < row; f++){
            len = len + strlen(str[f]); 
            length[f] =  strlen(str[f]);            
    }
   
    s = (char*) malloc((len+row) * sizeof(char));

    for(int x = 0; x < row; x++){
        for(int y = 0; y < length[x]; y++){
            *(s+y+m) = str[x][y];
        }
        *(s+m+length[x]) = '|';
        m = m+length[x]+1;
    } 
    free(length);  
    
    return s;
}