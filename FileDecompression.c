/*******************************************************************************
author     : Alex Szpakiewicz
description:Decompress a file using the Huffman algorithm

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "projectFunctions.h"

#define OUTPUT_FILENAME "decompressed.txt"
#define DATA_FILENAME "Huffman.txt"
#define MAX_NAME_SIZE 80/*constant-The maximum size of name*/
#define MAX_SIZE 50
/*Structure of a node*/
struct MinHeapNode
{
    char c;
    struct MinHeapNode *left, *right;
};
typedef struct MinHeapNode MinHeapNode_t;
/*Function prototypes*/
MinHeapNode_t* newNode(char c);
int getCodes(char *characters, int **codes, int *sizeofCodes);
int countLines(FILE *f0);
MinHeapNode_t*  createTree(char *characters, int **codes, int size, int sizeofCodes[]);
char* decodeData(MinHeapNode_t *root, int *data, char *decodedData, int lengthData);
void DecompressFile();
/*Create a new empty node*/
MinHeapNode_t* newNode(char c)
{
    MinHeapNode_t *temp = (MinHeapNode_t *)malloc(sizeof(MinHeapNode_t));
    temp->left = temp->right = NULL;
    temp->c = c;
    return temp;
}
MinHeapNode_t* newNode0()
{
    MinHeapNode_t *temp = (MinHeapNode_t *)malloc(sizeof(MinHeapNode_t));
    temp->left = temp->right = NULL;
    temp->c = '0';
    return temp;
}
/*COunt the lines from a file, so the number of characters in the huffman tree*/
int countLines(FILE *f0)
{
    int count = 0;
    char c;
    while((c = fgetc(f0)) != EOF){
        if (c == '\n') count = count + 1;
    }
    return count;
}
/*Create the huffman tree from the codes and the characters*/
MinHeapNode_t* createTree(char *characters, int **codes, int size, int sizeofCodes[]){
    MinHeapNode_t *root = newNode0();
    int i = 0;
    for (i = 0; i < size; i++) {
        MinHeapNode_t *temp = root;
        int j = 0;
        for(j=0;j<sizeofCodes[i];j++) {
            if (codes[i][j] == 0) {
                if (temp->left == NULL) {
                    temp->left = newNode0();
                }
                temp = temp->left;
            }
            else {
                if (temp->right == NULL) {
                    temp->right = newNode0();
                }
                temp = temp->right;
            }
        }
        temp->c = characters[i];

    }
    return root;
}
/*Decode the data from the huffman tree*/
char* decodeData(MinHeapNode_t *root, int data[], char *decodedData, int lengthData){
    MinHeapNode_t *temp = root;
    int i = 0;
    int j=0;
    for(i=0;i<lengthData;i++) {
        if (data[i] == 0) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
        if (temp->left == NULL && temp->right == NULL) {
            decodedData = realloc(decodedData, (j + 1) * sizeof(char));
            decodedData[j] = temp->c;
            j++;
            temp = root;
        }
    }
    return decodedData;
}
/*Decompress the file using the huffman tree and the compressed data
 * the file is given by the user and is checked if it exists
 * outputs a file containing the decompressed data*/
void DecompressFile() {
    FILE *f1 = NULL;
    FILE *f2 = NULL;
    FILE *f0 = NULL;


    int *data;
    char fileName[MAX_NAME_SIZE];
    int numbytes;
    int size;
    int lengthData = 0;
    char *characters = (char *)calloc(1 ,sizeof(char));
    int **codes = (int **)calloc(1 ,sizeof(int *));
    int *sizeofCodes = (int *)calloc(1 ,sizeof(int));
    char *decodedData = (char *)calloc(1 ,sizeof(char));

    printf("Enter the name of the file you want to decompress:\n");
    scanf("%s", fileName);
    f1 = fopen(fileName, "r");
    if (f1 == NULL) {
        printf("Error opening file\n");
        return;
    }
    f0 = fopen(DATA_FILENAME, "r");
    if (f0 == NULL) {
        printf("Error opening file\n");
        return ;
    }
    f2 = fopen(OUTPUT_FILENAME, "w");
    fseek(f1, 0L, SEEK_END);
    numbytes = ftell(f1);
    fseek(f1, 0L, SEEK_SET);
    data = (int*)calloc(numbytes, sizeof(int));
    if (data == NULL) {
        return;
    }
    char c;
    while((c = fgetc(f1)) != EOF) {
        data[lengthData] = c - '0';
        lengthData++;
    }
    fread(data, sizeof(int), numbytes, f1);
    lengthData = numbytes;
    size = countLines(f0);
    fseek(f0, 0, SEEK_SET);
    characters = (char *)realloc(characters, size * sizeof(char));
    codes = (int **)realloc(codes, size * sizeof(int *));
    sizeofCodes = (int *)realloc(sizeofCodes, size * sizeof(int));
    char line[MAX_SIZE];
    int i =0;
    while (fgets(line,MAX_SIZE,f0)) {
        characters[i] = line[0];
        int code[50];
        int j = 0;
        while (line[j+2] != '\n') {
            code[j] = line[j+2]-'0';
            j++;
        }
        codes[i] = (int *)calloc(j ,sizeof(int));
        int k = 0;
        for (k = 0; k < j; k++) {
            codes[i][k] = code[k];
        }
        sizeofCodes[i] = j;
        i++;
    }

    int a;
    MinHeapNode_t *root = NULL;
    root = createTree(characters, codes,size, sizeofCodes);
    decodedData = decodeData(root, data, decodedData, lengthData);
    fprintf(f2, "%s", decodedData);
    fclose(f1);
    fclose(f0);
    fclose(f2);
}

