/*******************************************************************************
author     : Alex Szpakiewicz
description:

*******************************************************************************/
#include <stdio.h>/*printf,scanf,fopen,fclose,fgetc,fputc*/
#include <stdlib.h>
#include <string.h>

#define OUTPUT_FILENAME "Ascii_Encryption.txt"/* constant-output file name*/
#define MAX_NAME_SIZE 80/*constant-The maximum size of name*/


/*Structures of the nodes and the tree*/
struct MinHeapNode
{
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};
typedef struct MinHeapNode MinHeapNode_t;

struct MinHeap
{
    int size;
    int capacity;
    MinHeapNode_t **array;
};
typedef struct MinHeap MinHeap_t;

/*Function prototypes*/
MinHeapNode_t* newNode(char data, int freq);
MinHeap_t * newMinHeap(int capacity);
void swapNode(MinHeapNode_t **a, MinHeapNode_t **b);
void minHeapify(MinHeap_t *minHeap, int idx);
MinHeapNode_t *extractMin(MinHeap_t *tree);
void insertMinHeap(MinHeap_t *minHeap, MinHeapNode_t *minHeapNode);
void buildMinHeap(MinHeap_t *minHeap);
MinHeap_t *createAndBuildMinHeap(char data[], int freq[], int size);
void printCodes(MinHeapNode_t *root, int arr[], int top, int **codes, char *data, int size, int sizeofCode[]);
void printArr(int arr[], int n);
MinHeapNode_t* buildHuffmanTree(char data[], int freq[], int size);
void HuffmanCodes(char data[], int freq[], int size, int **codes, int sizeofCodes[]);
void CompressFile();


/*Create a new node and a new tree*/
MinHeapNode_t* newNode(char c, int freq)
{
    MinHeapNode_t *temp = (MinHeapNode_t *)malloc(sizeof(MinHeapNode_t));
    temp->left = temp->right = NULL;
    temp->data = c;
    temp->freq = freq;
    return temp;
}
MinHeap_t * newMinHeap(int capacity)
{
    MinHeap_t *minHeap = (MinHeap_t *)malloc(sizeof(MinHeap_t));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode_t **)malloc(minHeap->capacity * sizeof(MinHeapNode_t *));
    return minHeap;
}
/*Swap the nodes*/
void swapNode(MinHeapNode_t **a, MinHeapNode_t **b)
{
    MinHeapNode_t *t = *a;
    *a = *b;
    *b = t;
}
/*Heapify the tree or sorting the branch in the correct order*/
void minHeapify(MinHeap_t *tree, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < tree->size && tree->array[left]->freq < tree->array[smallest]->freq)
        smallest = left;
    if (right < tree->size && tree->array[right]->freq < tree->array[smallest]->freq)
        smallest = right;
    if (smallest != index)
    {
        swapNode(&tree->array[smallest], &tree->array[index]);
        minHeapify(tree, smallest);
    }
}
/*Extract the minimum value node*/
MinHeapNode_t *extractMin(MinHeap_t *tree)
{
    MinHeapNode_t *temp = tree->array[0];
    tree->array[0] = tree->array[tree->size - 1];
    --tree->size;
    minHeapify(tree, 0);
    return temp;
}
/*Insert a new node to the heap*/
void insertMinHeap(MinHeap_t *tree, MinHeapNode_t *node)
{
    ++tree->size;
    int i = tree->size - 1;
    while (i && node->freq < tree->array[(i - 1) / 2]->freq)
    {
        tree->array[i] = tree->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    tree->array[i] = node;
}
/*Build the heap*/
void buildMinHeap(MinHeap_t *tree)
{
    int n = tree->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(tree, i);
    }
}
/*Create a new min heap*/
MinHeap_t *createAndBuildMinHeap(char data[], int freq[], int size)
{
    MinHeap_t *tree = newMinHeap(size);
    int i;
    for (i = 0; i < size; ++i){
        tree->array[i] = newNode(data[i], freq[i]);
    }
    tree->size = size;
    buildMinHeap(tree);
    return tree;
}
/*Print the codes*/
void printCodes(MinHeapNode_t *root, int arr[], int top, int **codes, char data[], int size, int sizeofCodes[])
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, codes, data, size, sizeofCodes);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, codes, data, size, sizeofCodes);
    }
    if (root->left==NULL && root->right==NULL)
    {
        printArr(arr, top);
        int i;
        for(i=0;i<size;i++){
            if(data[i]==root->data){
                codes[i] = (int*)malloc(sizeof(int)*top);
                int j;
                for(j=0;j<top;j++){
                    codes[i][j] = arr[j];
                }
                sizeofCodes[i] = top;
                break;
            }
        }
    }
}
void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}
/*Huffman coding*/
MinHeapNode_t* buildHuffmanTree(char data[], int freq[], int size)
{
    MinHeapNode_t *left, *right, *top;
    MinHeap_t *tree = createAndBuildMinHeap(data, freq, size);
    while (tree->size != 1)
    {
        left = extractMin(tree);
        right = extractMin(tree);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(tree, top);
    }
    return extractMin(tree);
}
void HuffmanCodes(char data[], int freq[], int size, int **codes, int sizeofCodes[])
{
    MinHeapNode_t *root = buildHuffmanTree(data, freq, size);
    int arr[100], top = 0;
    printCodes(root, arr, top, codes, data, size, sizeofCodes);
}

void CharacterFreq(char S[], int *frequency)
{
    int i = 0;
    while (S[i] != '\0') {
        frequency[S[i] - 32]++;
        i++;
    }
}

void CompressFile(){
    FILE *f1=NULL;
    FILE *f2=NULL;
    FILE *f3=NULL;
    char *c;
    int frequencyRaw[94] = { 0 };
    char fileName[MAX_NAME_SIZE];
    long numbytes;

    printf("Enter the name of the file you want to compress:\n");
    scanf("%s",fileName);

    f1 = fopen(fileName, "r");
    if( f1 == NULL){
        printf("File not found\n");
        return;
    }
    f2 = fopen("compressed.txt", "w");
    f3 = fopen("Tree.txt", "w");
    fseek(f1, 0L, SEEK_END);
    numbytes = ftell(f1);
    fseek(f1, 0L, SEEK_SET);
    c = (char*)calloc(numbytes, sizeof(char));
    if(c == NULL) {
        return;
    }
    fread(c, sizeof(char), numbytes, f1);
    CharacterFreq(c, frequencyRaw);
    char *data = (char*)calloc(1, sizeof(char));
    int *freq = (int*)calloc(1, sizeof(int));
    int i = 0;
    int j = 0;
    for (i = 0; i < 94; i++) {
        if (frequencyRaw[i] != 0) {
            data = (char*)realloc(data, (j+1) * sizeof(char));
            freq = (int*)realloc(freq, (j + 1) * sizeof(int));
            data[j] = i + 32;
            freq[j] = frequencyRaw[i];
            j++;
        }
    }
    int size = j;
    int **codes = (int**)calloc(size, sizeof(int*));
    int sizeOfCodes[j];
    HuffmanCodes(data, freq, size, codes, sizeOfCodes);
    int h;
    for (h = 0; h < size; h++) {
        fprintf(f3, "%c ", data[h]);
        int k;
        for (k = 0; k < sizeOfCodes[h]; k++) {
            fprintf(f3, "%d", codes[h][k]);
        }
        fprintf(f3, "\n");
    }
    int a;
    for(a=0;a< strlen(c);a++){
        int l;
        for (l = 0; l < size; l++) {
            if (c[a] == data[l]) {
                int m;
                for (m = 0; m < sizeOfCodes[l]; m++) {
                    fprintf(f2, "%d", codes[l][m]);
                }
                break;
            }
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}