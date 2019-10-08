#include<stdio.h>
#include<stdlib.h>
#include "chiperApp.h"
#include "operations.h"

short int operation;
char keyword[10];
char inputText[1000];

void encryptView(){ //ENCRYPTION APP
    //Get inputs from user
    printf("Enter the plaintext that you want to encrypt (MAX LENGTH 1000) : ");
    scanf(" %s" ,inputText);

    printf("Enter the keyword (MAX LENGTH 10) :");
    scanf(" %s" ,keyword);

    char * output; //Pointed array from "operations.c"
    output = encryptText(inputText, keyword);
    printf("\nEncrypted Text: %s", output);
}

void decryptView(){ //DECRYPTION APP
    //Get inputs from user
    printf("Enter the encrypted text that you want to decrypt: ");
    scanf(" %s" ,inputText);

    printf("Enter the keyword:");
    scanf(" %s" ,keyword);

    char * output; //Pointed array from "operations.c"
    output = decryptText(inputText, keyword);
    printf("\nDecrypted Text: %s", output);
}

int main(){
printf("\nWELCOME TO THE VIGERENE CHIPER ENCRYPTER/DECRYPTER");

int done = 1;
while (done == 1){  //APPLICATION LOOP

    printf("\n\nChoose the operation you want to commit \n1)Encrypt \n2)Decrypt \nEnter Query Number:");
    scanf(" %hd" ,&operation);

    switch(operation) {
        case 1:
            encryptView();
            break; 
        case 2:
            decryptView();
            break;
        default :
            printf("WRONG INPUT");
    }
    printf("\n\nDo you want to continue? (Y/N) : ");
    char cont;
    scanf(" %c" ,&cont);
    if (cont == 'N' || cont == 'n'){
        break;
    }else if(cont == 'Y' || cont == 'y'){
        continue;
    }else{
        printf("WRONG INPUT TERMINATING APP");
        break;
    }
}
    return 0;
}