#include<stdio.h>
#include<stdlib.h>
#include "operations.h"
#include<string.h>

char output[1000];

//get lenght of relevant part of char array
int string_length(char str[]) {
   int count = 0;
 
   while (str[count] != '\0')
      count++;
 
   return count;
}

char * encryptText(char plaintext[1000], char keyword[10]){

    int keywordLen = string_length(keyword);
    int keywordLooper = 0;

    memset(output,'\0',1000); // Clear array to remove leftovers from previous operations

    int i;
    for (i=0; i<string_length(plaintext); i++){
        output[i] = plaintext[i] + keyword[keywordLooper] - 65; //Modified letter according to given instructions

        if (keywordLooper+1 < keywordLen){
            keywordLooper++;
        }else{
            keywordLooper = 0; //Point start of keyword when reached end
        }
    }
    return output;    
}

char * decryptText(char encryptedText[1000], char keyword[10]){
    int keywordLen = string_length(keyword);
    int keywordLooper = 0;

    memset(output,'\0',1000); // Clear array to remove leftovers from previous operations

    int i;
    for (i=0; i<string_length(encryptedText); i++){
        output[i] = encryptedText[i] - keyword[keywordLooper] + 65; //Modified letter according to given instructions

        if (keywordLooper+1 < keywordLen){
            keywordLooper++;
        }else{
            keywordLooper = 0; //Point start of keyword when reached end
        }
    }
    return output;    
}