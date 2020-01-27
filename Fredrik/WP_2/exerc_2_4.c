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

char palindromeWord[MAX];
char compareLetter[MAX];

int main()
{
    printf("Enter a word to check if its a palindrome : ");
    fgets(palindromeWord, MAX, stdin);

    for (int i = 0; i < strlen(palindromeWord) - 1; i++)
    {
        compareLetter[i] = palindromeWord[i];
        int lastChar = strlen(compareLetter) - 1;
        if (palindromeWord[i] == compareLetter[lastChar])
        {
            printf("%d, %c is equal \n", i, palindromeWord[i]);
                }
        else
        {
            printf("Characters are not the same \n");
        }
    }
}
