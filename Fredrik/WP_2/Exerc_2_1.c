/*====================================
File name: exerc_2_1.c
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
#include <string.h>
#define MAX 20
char word[MAX];
void copyString()
{
    char savedWord[MAX];
    savedWord[MAX];
    for (int i = 0; i < MAX + 1; i++)
    {
        savedWord[i] = word[i];
    }

    printf("printed from copyString : %s", savedWord);
}

int main()
{

    char saved[MAX];
    printf("Type something \n");
    fgets(word, MAX, stdin);

    // a ) copy the string to another string
    strcpy(saved, word);
    printf("printed from strcpy() : %s", saved);
    copyString();
}