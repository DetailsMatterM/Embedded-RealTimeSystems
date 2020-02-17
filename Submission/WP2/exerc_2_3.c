/* ====================================
File name: exerc_2_3.c 
Date: 2020-02-06
Group nr 7
Members that contribute to the solutions
Fredrik Ullman
Mikael Köse Jansson
Moritz Denke

Demonstration code: [45947] Important , No code no exercise points !
====================================== */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("To use this program, enter just 2 strings.\nType : %s firstWord secondWord\n", argv[0]);
        return 1;
    }
    printf(" First word  : %s\n Second word : %s\n", argv[1], argv[2]);
    int compare = strcmp(argv[1], argv[2]);
    printf("Compared by using strcmp function: ");
    if (compare == 0)
    {
        printf("%s and %s\n ", argv[1], argv[2]);
        printf(" Words are identical! \n");
    }
    else
    {
        printf(" Words are not identical!\n");
    }

    int allCorrect = 1;
    printf("Compared by manual comparison: \n");
    if(strlen(argv[1]) == strlen(argv[2])) {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (argv[1][i] == argv[2][i])
            {
                printf("Letter %d identical \n", i);
            }
            else
            {
                printf(" Letter at index %d is not identical to the compared letter\n", i);
                allCorrect = 0;
            }
        }
    } else {
        allCorrect = 0;
    }
    if (allCorrect == 1)
    {
        printf(" Words are identical\n");
    }
    else
    {
        printf( "Sorry, the words are not identical\n");
    }
    
    return 0;
}