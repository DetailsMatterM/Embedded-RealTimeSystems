/*====================================
File name: exerc_2_4.c
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
#define MAX 50
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char palinWord[MAX];

char compare[MAX];
int lastInt;
int last;
int main()
{

    printf("Enter a word to check if its a palindrome : ");
    fgets(palinWord, MAX, stdin);
    lastInt = strlen(palinWord) - 2;
    last = strlen(palinWord) - 1;
    printf("%d", last);
    if (last % 2 == 0)
    {
        printf(" even word! \n");
        swapLetters();
    }
    else
    {
        printf("Not an even word! \n");

        swapLetters();
    }
}

// int m = atoi(palinWord); //convert string to integer
int swapLetters()
{

    lastInt = strlen(palinWord) - 2;
    last = strlen(palinWord) - 1;
    for (int i = 0; i < lastInt; i++)
    {

        if (palinWord[i] == palinWord[lastInt])
        {
            printf("%d : %c | %c : %d \n", i, palinWord[i], palinWord[lastInt], lastInt);
            lastInt--;
        }
        else
        {
            printf("Nope ");
        }
    }
}
