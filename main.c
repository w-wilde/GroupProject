#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projectFunctions.h"
/* For this checkpoint, We put the main and the prototypes of our methods in the projectFunctions.h file.
 In the future, we will also have a makefile, but we need to look more into it as it is a new concept for all of us*/

#define TERMINATE 5 /* Assign last int value of Menu Options */

/**********************************
Author     : William Trang
Description: 
  Displays  Menu Select Options, identifies & carries out the Menu-Option selected by User
***********************************/
int main() {
    int opchoice;
    while(opchoice != TERMINATE)
      /* "Menu Options shown is not the final" - Will */
        {
            printMenu(); /* prints menu options for user */

            printf("Enter your choice>\n"); /* Identifies user's menu choice */
            scanf("%d", &opchoice);

            switch (opchoice)
            {
                case 1 : /* Menu Opt1: "Scan Image" */
                    /* Insert function call for scanning */
                    break;
                case 2 : /* Menu Opt2: "Clean database" */
                    /* Insert function call */
                    break;
                case 3 : /* Menu Opt3: "Encrypt Image" */
                    /* Insert function call */
                    break;
                case 4 : /* Menu Opt4: "Decrypt Image" */
                    /* Insert function call */
                    break;    
                case TERMINATE : /* Menu Opt6: "Exit program" */
                    break; /* Breaks out of loop & Ends program */
                default : /* selection is of value not listed for menu */
                    printf("Invalid choice.");
            }
        }
    return 0;
}
/**********************************
Author     : William Trang
Description: 
  displays the Select Menu to User
Inputs : None
Outputs: None
***********************************/
void printMenu(void)
  /* "Menu Options shown is not the final" - Will */
{
    printf("\n\n"
     "1. Scan Image\n"
     "2. Clean Database\n"
     "3. Encrypt Image\n"
     "4. Decrypt Image\n"
     "5. Exit the program\n");
}
