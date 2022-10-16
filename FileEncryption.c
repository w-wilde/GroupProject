/*******************************************************************************
author     : Alex Szpakiewicz
description:

*******************************************************************************/

#include "project_utils.h"
#include<stdio.h>/*printf,scanf,fopen,fclose,fgetc,fputc*/

#define OUTPUT_FILENAME "Ascii_Encryption.txt"/* constant-output file name*/
#define MAX_NAME_SIZE 80/*constant-The maximum size of name*/

void encryptFile()
{
    FILE *f1=NULL;
    FILE *f2=NULL;
    int key;
    char c;
    char fileName[MAX_NAME_SIZE];

    printf("Enter the name of the file you want to encrypt:\n");
    scanf("%s",name);

    /*Get the file name from the user
    and input to the function to open the file*/

    f1 = fopen(name, "r");
    if( f1 == NULL)
        printf("File not found\n");
        return;
    }
    printf("Input the key which is a number between 1 and 93:\n");
    scanf("%d",&key);
    while(key<0||key>93)
    {
        printf("Invalid key, please input a number between 1 and 93:\n");
        printf("Input a new key：");
        scanf("%d",&key);
    }
    f2 = fopen(OUTPUT_FILENAME, "w");

    while((c=fgetc(f1))!=EOF)
    {
        c=(c-32+key)%94+32;
        fputc(c,f2);
    }
    fclose(f2);
    fclose(f1);
    printf("The file is encrypted!\n");
}

