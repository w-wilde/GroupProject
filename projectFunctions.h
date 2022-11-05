#ifndef PROJECT_FUNCTIONS_H_INCLUDED
#define PROJECT_FUNCTIONS_H_INCLUDED


/* This method would compress th desired object using the Huffman algorithm*/
void CompressFile();
/* This method would decompress the desired object*/
void DecompressFile();

/* This method would encrypt a file using the autokey algorithm*/
void encryptFile();
/* This method would decrypt a file*/
void decryptFile();
/* This method would encrypt/decrypt a file with the XOR method*/
void encryptDecrypt();

#endif