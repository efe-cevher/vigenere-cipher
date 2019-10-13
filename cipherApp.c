#include<stdio.h>
#include<stdlib.h>
#include "operations.h"
#include "cipherApp.h"

short int operation;
char keyword[10];
char inputText[200];

void encryptView(){ //ENCRYPTION APP
    //Get inputs from user
    printf("Enter the plaintext that you want to encrypt (MAX LENGTH 200) : ");
    scanf(" %s" ,inputText);

    printf("Enter the keyword (MAX LENGTH 10) :");
    scanf(" %s" ,keyword);

    char * output; //Pointed array from "operations.c"
    output = encryptText(inputText, keyword);
    printf("\nEncrypted Text: %s", output);
}

void decryptView(){ //DECRYPTION APP
    //Get inputs from user
    printf("Enter the encrypted text that you want to decrypt (MAX LENGTH 200) : ");
    scanf(" %s" ,inputText);

    printf("Enter the keyword (MAX LENGTH 10) :");
    scanf(" %s" ,keyword);

    char * output; //Pointed array from "operations.c"
    output = decryptText(inputText, keyword);
    printf("\nDecrypted Text: %s", output);
}

int main(){
printf("\nWelcome to the Vigenere Cipher Encrypter/Decrypter\n");

short int done = 1;
while (done == 1){  //APPLICATION LOOP
    printf("\nChoose the operation you want to commit \n1)Encrypt \n2)Decrypt \nEnter Query Number (1 or 2): ");
    scanf(" %hd" ,&operation);

    switch (operation){ //Choose Encryption or Decryption
        case 1:
            encryptView();
            break; 
        case 2:
            decryptView();
            break;
        default :
            printf("\nWRONG INPUT ");
    }

    char cont;
    printf("\n\nDo you want to run again? (Y/N) : ");
    scanf(" %c" ,&cont);

    if (cont == 'Y' || cont == 'y'){ //Check if user wants to continue using app or terminate
        continue;
    }else if(cont == 'N' || cont == 'n'){
        printf("Terminating app, thank you for using.\n");
    }else{
        printf("\nWRONG INPUT TERMINATING APP\n");
    }
    done = 0;
}
    return 0;
}