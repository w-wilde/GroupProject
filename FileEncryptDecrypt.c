
/*******************************************************************************
author     : Joshua Velasco
description: encrypts/decrypts a file with the XOR method
*******************************************************************************/
#include <stdio.h>/*printf,scanf,fopen,fclose,fgetc,fputc*/
#include<string.h>

#define MAX_NAME_SIZE 80/*constant-The maximum size of name*/
/*Function prototypes*/
void encryptDecrypt();
/*Function definitions*/
/*Encrypt the file using the XOR algorithm and saves the encrypted file
 CHecK if the file containing the data and if it doesnt exist, quits the function*/
void encryptDecrypt()
{
    FILE *f1=NULL;
    FILE *f2=NULL;
    int xorkey;
    char c;
    char fileName[MAX_NAME_SIZE];
    char outputFileName[MAX_NAME_SIZE];

    printf("Enter the name of the file you want to encrypt/decrypt:\n");
    scanf("%s",fileName);

    /*Get the file name from the user
    and input to the function to open the file*/

    f1 = fopen(fileName, "r");
    if( f1 == NULL)
    {
        printf("File not found\n");
        return;
    }

    printf("Enter XOR key of 6 numbers without 0: ");
    scanf("%d", &xorkey);
    int test =0;
    while(test==0)
    {
        if(xorkey<100000||xorkey>999999||xorkey%10==0||xorkey%100==0||xorkey%1000==0||xorkey%10000==0||xorkey%100000==0)
        {
            printf("Invalid key, please input a number between 1 and 93:\n");
            printf("Input a new key：");
            scanf("%d",&xorkey);
        }
        else
        {
            test=1;
        }
    }
    printf("Enter the name of the output file:\n");
    scanf("%s",outputFileName);
    f2 = fopen(outputFileName, "w");
    int encrypted = 0;
    while((c=fgetc(f1))!=EOF)
    {
        encrypted = c^xorkey;
        fputc(encrypted,f2);
    }
    fclose(f2);
    fclose(f1);
}

