#ifndef PROJECT_FUNCTIONS_h_
#define PROJECT_FUNCTIONS_h_

/* This method would create the user menu*/
static void Menu();
/* This method would read the user input and call the subsequent method*/
static void ReadInput();

/* This method would compress th desired object using the Huffman algorithm*/
static void CompressFile();
/* This method would decompress the desired object*/
static void DecompressFile();

/* This method would encrypt a file using the autokey algorithm*/
static void encryptFile();
/* This method would decrypt a file*/
static void decryptFile();

/* This method would sort an input file based on parameters inputted by the user*/
static void SortFile();
/* This method would exit the program*/
static void Exit();

#endif