#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool split_string(char **str_parsen, char *buffer, char delimiter, int *numb_tokens);


int main() {
   char string[50] = "$GPAAM,A,A,0.10,N,WPTNME*32";
   char **tokens= (char**)malloc(sizeof(char *)* (20));
   int token;
   char delimiter = ',';
   split_string(tokens ,string, delimiter, &token);
    
        for (int i = 0; i < token; i++) {
            printf("data split[%d]: %s\n", i, tokens[i]);
        }
        printf("number of token %d\n",token);
        
    
    free(tokens);
   return 0;
}
/*
Result:
data split[0]: $GPAAM
data split[1]: A
data split[2]: A
data split[3]: 0.10
data split[4]: N
data split[5]: WPTNME*32
number of token 6
*/

/*
brief: split string with delimiter
param tokens: pointer to pointer char token
param buffer: buffer string data
param delimiter: character for split string
param numb_tokens: number of tokens
return: false or true
*/
bool split_string(char **tokens, char *buffer, char delimiter, int *numb_tokens){
    bool result = false;
    int m=0;
    int j=1;
    int count = 0;
    for(int i=0;i<strlen(buffer);i++){
        
        if(buffer[i] == delimiter){
            j++;            
        }
    }
    *numb_tokens = j;
    char *buf = strtok(buffer, &delimiter);
    
    while (buf != NULL) {
        tokens[count++] = strdup(buf);
        buf = strtok(NULL, &delimiter);
    }
    
    return result;
}