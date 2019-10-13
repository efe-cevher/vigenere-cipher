#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "operations.h"

char output[200];

int string_length(char str[]) { //Get lenght of relevant part of char array
    int count = 0;
    while (str[count] != '\0')
      count++;

    return count;
}

char * encryptText(char plaintext[200], char keyword[10]){
    int keywordLen = string_length(keyword);
    int keywordLooper = 0;

    memset(output,'\0',200); // Clear array to remove leftovers from previous operations

    int i;
    for (i=0; i<string_length(plaintext); i++){
        output[i] = (( plaintext[i] + keyword[keywordLooper]) % 26) + 'A'; //Modified letter according to vigenere cipher

        if (keywordLooper+1 < keywordLen){
            keywordLooper++;
        }else{
            keywordLooper = 0; //Point start of keyword when reached end
        }
    }
    return output;    
}

char * decryptText(char encryptedText[200], char keyword[10]){
    int keywordLen = string_length(keyword);
    int keywordLooper = 0;

    memset(output,'\0',200); // Clear array to remove leftovers from previous operations

    int i;
    for (i=0; i<string_length(encryptedText); i++){
        output[i] = (((encryptedText[i] - keyword[keywordLooper]) + 26) % 26) + 'A'; //Modified letter according to vigenere cipher

        if (keywordLooper+1 < keywordLen){
            keywordLooper++;
        }else{
            keywordLooper = 0; //Point start of keyword when reached end
        }
    }
    return output;    
}