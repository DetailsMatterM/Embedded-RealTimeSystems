/*---------------------------------------*
*   Demo ex : A file register    **
*   File simple_fileex_2.c              **
*   Peter Lundin 2017-11-17             **
*----------------------------------------*/

#include <stdio.h>
#include <curses.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    char lname[20];
    char fnamn[20];
} POSTTYPE;

//--- Function declarations ----------
int enter_rec(POSTTYPE reg[], int actual_number);
void store(POSTTYPE reg[], int num);
int readfile(POSTTYPE reg[]);

int numal = 0;
//----------- Main program --------------

int main()
{
    int number_of = 0;
    POSTTYPE card[MAX];
    printf("Time for start\n");
    number_of = enter_rec(card, number_of);
    printf(" Number of records is %d", number_of);
    printf("\n");
    store(card, number_of);
    puts("\n Now it is stored");
    //  getch();
    number_of = readfile(card);
    printf("\n Number of records in file is  %d . ", number_of);
    puts(card[2].lname);
    gets();
    return 0;
}

int enter_rec(POSTTYPE reg[], int actual_number)
{
    int i, l, k;
    char temp[20];
    for (i = actual_number; i < MAX; i++)
    {
        printf("\n Enter first name ( Enter 'a' at any time to quit ) :  ");
        gets(temp);
        if (strlen(temp) == 1 && temp[0] == 'a')
            break;
        strcpy(reg[i].fnamn, temp);
        printf("\n Enter last name  :  ");
        gets(temp);
        strcpy(reg[i].lname, temp);
        //gets(temp);// Clears eventual rest characters in buffer
    }
    return (i);
}

void store(POSTTYPE *regptr, int num)
{
    FILE *fileptr;
    int n;
    if ((fileptr = fopen("creg1.dat", "wb")) == NULL)
    {
        printf("\n Can not create the file");
        exit(1);
    }
    for (n = 0; n < num; n++)
    {
        fwrite(regptr, sizeof(POSTTYPE), 1, fileptr);
        regptr++;
    }

    fclose(fileptr);
}
int readfile(POSTTYPE *regptr)
{
    int n = 0;
    FILE *fileptr;
    if ((fileptr = fopen("creg1.dat", "rb")) == NULL)
    {
        printf("\n Can not open file");
        exit(1);
    }
    // --------   Reads all file  --------
    while (!feof(fileptr))
    {
        if (fread(regptr, sizeof(POSTTYPE), 1, fileptr))
        {
            printf("\n %s", regptr->lname);
            n++;
            regptr++;
        }
    }
    fclose(fileptr);
    return n;
}
