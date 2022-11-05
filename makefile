CC = gcc
CFLAGS = -Wall -Werror -ansi

main.out: main.o FileEncryption.o FileDecryption.o FileCompression.o FileDecompression.o
	$(CC) $(CFLAGS) -o main.out main.o FileEncryption.o FileDecryption.o FileCompression.o FileDecompression.o FileEncryptDecrypt.o

main.o: main.c projectFunctions.h
	$(CC) $(CFLAGS) -c -o main.o main.c

FileEncryption.o: FileEncryption.c projectFunctions.h
	$(CC) $(CFLAGS) -c -o FileEncryption.o FileEncryption.c

FileDecryption.o: FileDecryption.c projectFunctions.h
	$(CC) $(CFLAGS) -c -o FileDecryption.o FileDecryption.c

FileCompression.o: FileCompression.c projectFunctions.h
	$(CC) $(CFLAGS) -c -o FileCompression.o FileCompression.c

FileDecompression.o: FileDecompression.c projectFunctions.h
	$(CC) $(CFLAGS) -c -o FileDecompression.o FileDecompression.c

FileEncryptDecrypt.o: FileEncryptDecrypt.c projectFunctions.h
	$(CC) $(CFLAGS) -c -o FileEncryptDecrypt.o FileEncryptDecrypt.c

clean:
	rm main.out main.o FileEncryption.o FileDecryption.o FileCompression.o FileDecompression.o FileEncryptDecrypt.o

cleanf:
	rm compressed.txt decompressed.txt Huffman.txt encrypted.txt decrypted.txt XOR.txt