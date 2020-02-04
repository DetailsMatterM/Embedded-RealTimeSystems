/* ====================================
File name: exerc_1_2.c
Date: 2020-01-21
Group nr 7
====================================== */

#include <stdio.h>
#include <string.h>
#define MAX 100

void main()
{
    char s[MAX];
    int count = 0, i;

    printf("Type a sentence:\n");
    scanf("%[^\n]s", s);
  
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' && s[i + 1] != ' ')
            count++;
    }
    printf("Number of words: %d\n", count + 1);
}