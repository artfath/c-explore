#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool split_string(char **str_parsen, char *buffer, char delimiter, int *numb_tokens);


int main() {
   char string[] = "$GPAAM,A,A,0.10,N,WPTNME*32";
   char **tokens= (char**)malloc(sizeof(char *)* (20));
   int token;
   char delimiter = ','; //',' or '-'
   int status;
   status = split_string(tokens ,string, delimiter, &token);
   printf("status %d\n", status);
    for (int i = 0; i < token; i++) {
        printf("data split[%d]: %s\n", i, tokens[i]);
    }
    printf("number of token %d\n",token);            
    
    free(tokens);
   return 0;
}
/*
Result:
status 1
data split[0]: $GPAAM
data split[1]: A
data split[2]: A
data split[3]: 0.10
data split[4]: N
data split[5]: WPTNME*32
number of token 6

status 0
data split[0]: $GPAAM,A,A,0.10,N,WPTNME*32
number of token 1
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
    bool result = true;
    int m=0;
    int j=1;
    int count = 0;
    for(int i=0;i<strlen(buffer);i++){
        
        if(buffer[i] == delimiter){
            j++;            
        }
    }

    if(j==1){
        result = false;
        *numb_tokens = j;
        tokens[count++] = strdup(buffer);
    } else {
        *numb_tokens = j;
        char *buf = strtok(buffer, &delimiter);
        
        while (buf != NULL) {
            tokens[count++] = strdup(buf);
            buf = strtok(NULL, &delimiter);
        }
    }
    
    return result;
}