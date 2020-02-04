/*====================================
File name: exerc_2_3.c
Date: 2020-02-07
Group nr 7
Members that contribute to the solutions
Moriz Denke 
Mikael Köse Jansson 
Fredrik Ullman
Member not present at demonstration time:
Yyyyyy yyyy
Demonstration code: [<Ass code 1-4> <abc>] Important , No code no exercise points !
======================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        printf("Type : %s firstWord secondWord and option 1 or 2\n", argv[0]);
        return 1;
    }
    printf(" First word  : %s\n Second word : %s\n option : %s \n", argv[1], argv[2], argv[3]);

    char option = argv[3][0];

    // compare using the strcmp function
    if (option == '1')
    {
        int compare = strcmp(argv[1], argv[2]);
        if (compare == 0)
        {
            printf("%s and %s\n ", argv[1], argv[2]);
            printf(" Words are identical ! ");
        }
        else
        {
            printf(" Words are not identical ! ");
        }
    }
    //compare without use of strcmp function
    else if (option == '2')
    {

        int allCorrect = 1;

        for (int i = 0; i < strlen(argv[1]) || i < strlen(argv[2]); i++)
        {
            if (argv[1][i] == argv[2][i])
            {
                printf("Letter %d identical \n", i);
            }
            else
            {
                printf(" Letter %d Words are not identical \n", i);
                allCorrect = 0;
            }
        }
        if (allCorrect == 1)
        {
            printf("Words are identical \n");
        }
        else if (allCorrect == 0)
        {
            printf("Sorry, not all letters were identical \n");
        }
    }
    else
    {
        printf("Incorrect option , 1 or 2 ");
    }

    return 0;
}
