#include <stdio.h>
#include <stdlib.h>

#include "projectFunctions.h"
/********************************************************************************
Name   : 48430 Fundamentals of C-Programming - Lab07 Group05 Project
Members:
    Alex Szpakiewicz, Joshua Velasco, William Trang

Project Description:
    To encrypt, compress, decompress, & decrypt fed data, for safe
    storage, transfer, and access of such information.

Additional Notes:
    There is an accompanying written report further describing the
    individual aspects of the project.
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projectFunctions.h"

/* For this checkpoint, We put the main and the prototypes of our methods in the projectFunctions.h file.
 We also have a makefile to build and compile the methods*/

/********************************************************************************
Function Prototypes
********************************************************************************/
void printMenu(void);


/********************************************************************************
Author     : William Trang
Description:
  Displays  Menu-Select Options, identifies & carries out the Menu-Option selected by User,
  uses sentinel-controlled loop
********************************************************************************/
int main(void)
{
    int opchoice;
    while(opchoice != 5) /* Loops Menu-Select until TERMINATED */
    {
        printMenu(); /* prints menu options for user */
        printf("Enter your choice>\n");
        scanf("%d", &opchoice); /* Intakes user's menu choice */

        switch (opchoice) /* Matches User's choice with Select-Option */
        {
            /* "Menu Options shown is just the layout of the MenuSelect" - Will */

            case 1 : /* Menu Opt1: "Compress File" */
                printf("Compress File\n");
                CompressFile();
                break;
            case 2 : /* Menu Opt2: "Decompress File" */
               DecompressFile();
                break;
            case 3 : /* Menu Opt3: "Encrypt file with autokey" */
                encryptFile();
                break;
            case 4 : /* Menu Opt4: "Decrypt file with autokey" */
                decryptFile();
                break;

            case 5: /* Menu Opt5: "Exit program" */
                exit(0); /* Terminates program */
                break; /* Breaks out of loop & Ends program */

            default : /* selection is of value not listed for menu */
                printf("Invalid choice.\n");
        }
    }
    printf("\nEnd of Program. Have a nice day. :)\n");
    return 0;
}
/********************************************************************************
Author     : William Trang
Description:
  displays the Select Menu to User
Inputs : None
Outputs: None
********************************************************************************/
void printMenu(void)
/* "Current menu is just the layout atm" - Will */
{
    printf("\n"
           "Welcome to our software program! \n"
           "What would you like to do : \n"
           "1. Compress File\n"
           "2. Decompress File\n"
           "3. Encrypt File with autokey\n"
           "4. Decrypt File with autokey\n"
           "5. Exit the program\n");
}

