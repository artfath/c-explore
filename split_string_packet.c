#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_PACKET 10
bool split_string(char *message, char *packet1, char *packet2, int size);


int main() {
   char message[] = "$GPAAM,A,A,0.10,N,WPTNME*32\r\n";
   
   int size=strlen(message);
   char packet1[20];
   char packet2[20];
   split_string(message ,packet1, packet2, size);
   printf("message: %s\n",message);
   printf("packet1: %s\n",packet1);
   printf("packet2: %s\n",packet2);       

   return 0;
}
/*
Result:
message: $GPAAM,A,A,0.10,N,WPTNME*32


packet1: $GPAAM,A,A
packet2: ,0.10,N,WPTNME*32


*/

/*
brief: split string to 2 packet
param message: pointer to split
param packet1: pointer to packet 1 data
param packet2: character for split string
param size: size of message
return: false or true
*/
bool split_string(char *message, char *packet1, char *packet2, int size){
    bool result = true;
    int m=0;
    int j=1;
    
    if(size <= SIZE_PACKET){
       strncpy(packet1, message, SIZE_PACKET);
        packet1[SIZE_PACKET]='\0'; 
        memset(packet2, '\0', 1);
    } else {
        strncpy(packet1, message, SIZE_PACKET);
        packet1[SIZE_PACKET]='\0';
        strcpy(packet2, message + SIZE_PACKET);
    }
        
    return result;
}