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

int main()
{
    char word[MAX];
    char saved[20];
    char savedInput[MAX];
    printf("Type something \n");
    fgets(word, MAX, stdin);

    // a ) copy the string to another string
    strcpy(saved, word);

    printf("%s", saved);
}