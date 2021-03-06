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
int truePalindrome = 1;

int swapLetters();
int isPalindrome();

int main()
{

    printf("Enter a word to check if its a palindrome : ");

    fgets(palinWord, MAX, stdin);

    swapLetters();

    isPalindrome();
}
int swapLetters()
{

    lastInt = strlen(palinWord) - 2;

    last = strlen(palinWord) - 1;
    if (last % 2 == 0)
    {

        for (int i = 0; i < lastInt; i++)
        {

            if (palinWord[i] == palinWord[lastInt])
            {
                lastInt--;
            }
            else
            {
                truePalindrome = 0;
            }
        }
    }
    else
    {
        int middleCharacter = (strlen(palinWord) / 2);
        int middleCharacterIndexPosition = middleCharacter - 1;

        for (int i = 0; i < lastInt; i++)
        {

            if (palinWord[i] == palinWord[lastInt])
            {
                lastInt--;
            }
            else
            {
                truePalindrome = 0;
            }
        }
    }
}
int isPalindrome()
{
    if (truePalindrome == 1)
    {
        printf("It's a palindrome !");
    }
    else if (truePalindrome == 0)
    {
        printf("Nope, this is not a palindrome !  ");
    }
}
