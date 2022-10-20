/*******************************************************************************
author     : Alex Szpakiewicz
description:

*******************************************************************************/
#include "project_utils.h"
#include <stdio.h>/*printf,scanf,fopen,fclose,fgetc,fputc*/

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

struct Character{
    char character;
    int frequency;
    int code[100];
};
typedef struct Character Character_t;

/*Create a new node and a new tree*/
MinHeapNode_t newNode(char c, int freq)
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
/*Swap the nodes*/
void swapNode(node **a, node **b)
{
    node *t = *a;
    *a = *b;
    *b = t;
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
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(tree, i);
}

/*Create a new min heap*/
MinHeap_t *createAndBuildMinHeap(char data[], int freq[], int size)
{
    MinHeap_t *tree = newMinHeap(size);
    int i;
    for (i = 0; i < size; ++i)
        tree->array[i] = newNode(data[i], freq[i]);
    tree->size = size;
    buildMinHeap(tree);
    return tree;
}
/*Print the codes*/
void printCodes(MinHeapNode_t *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right))
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}
/*Huffman coding*/
void buildHuffmanTree(char data[], int freq[], int size)
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
    printCodes(extractMin(tree), arr, 0);
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode* root
            = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top);
}

void CompressFile(){
    FILE *f1=NULL;
    FILE *f2=NULL;
    Character_t characters[94];
    char c;
    char fileName[MAX_NAME_SIZE];

    printf("Enter the name of the file you want to compress:\n");
    scanf("%s",filename);

    f1 = fopen(filename, "r");
    if( f1 == NULL){
        printf("File not found\n");
        return;
    }
    while((c = fgetc(f1)) != EOF){
        characters[c-32].character = c;
        characters[c-32].frequency++;
    }


}
