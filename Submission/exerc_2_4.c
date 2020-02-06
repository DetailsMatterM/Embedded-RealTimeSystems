/* ====================================
File name: exerc_2_4.c 
Date: 2020-02-06
Group nr 7
Members that contribute to the solutions
Fredrik Ullman
Mikael Köse Jansson
Moritz Denke

Demonstration code: [45302] Important , No code no exercise points !
====================================== */
#include <stdio.h>
#include <string.h>

#define MAX 20

int main() {
    char palStr[MAX];
    char revPalStr[MAX];

    printf("Please input a word: \n");
    gets(palStr);

    strcpy(revPalStr, palStr);          //Copy string
    strrev(revPalStr);                  //Reverse string

    if (strcmp(palStr, revPalStr) != 0) {
        printf("\n%s : This word is no palindrome", palStr);
    } else
    {
        printf("\n%s : This word is a palindrome", palStr);
    }
    
    return 0;
}