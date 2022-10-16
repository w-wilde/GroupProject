#ifndef PROJECT_FUNCTIONS_h_
#define PROJECT_FUNCTIONS_h_

/* This method would create the user menu*/
static void Menu();
/* This method would read the user input and call the subsequent method*/
static void ReadInput();

/* This method would compress th desired object using the Huffman algorithm*/
static void Compress();
/* This method would decompress the desired object*/
static void Decompress();

/* This method would encrypt a file using the autokey algorithm*/
static void EncryptFile();
/* This method would decrypt a file*/
static void DecryptFile();

/* This method would encrypt an image using the XOR algorithm*/
static void EncryptImage();
/* This method would decrypt an image*/
static void DecryptImage();

/* This method would sort an input file based on parameters inputted by the user*/
static void SortFile();
/* This method would exit the program*/
static void Exit();

#endif