/*====================================
File name: exerc_1_3.c (or cpp)
Date: 2020-01-21
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
#define MAX 50
char word[MAX];

int main()
{
    encryption();
}

int encryption()
{
    printf("Enter a word to encrypt it : ");
    while (1)
    {

        fgets(word, MAX, stdin);
        printf("word is : %s\n", word);

        for (int i = 0; i < MAX; i++)
        {
            if (word[i] == 'a')
            {
                word[i] = 'n';
            }
            else if (word[i] == 'n')
            {
                word[i] = 'a';
            }
            if (word[i] == 'b')
            {
                word[i] = 'o';
            }
            else if (word[i] == 'o')
            {
                word[i] = 'b';
            }
            if (word[i] == 'c')
            {
                word[i] = 'p';
            }
            else if (word[i] == 'p')
            {
                word[i] = 'c';
            }

            if (word[i] == 'd')
            {
                word[i] = 'q';
            }
            else if (word[i] == 'q')
            {
                word[i] = 'd';
            }
            if (word[i] == 'e')
            {
                word[i] = 'r';
            }
            else if (word[i] == 'r')
            {
                word[i] = 'e';
            }
            if (word[i] == 'f')
            {
                word[i] = 's';
            }
            else if (word[i] == 's')
            {
                word[i] = 'f';
            }
            if (word[i] == 'g')
            {
                word[i] = 't';
            }
            else if (word[i] == 't')
            {
                word[i] = 'g';
            }
            if (word[i] == 'h')
            {
                word[i] = 'u';
            }
            else if (word[i] == 'u')
            {
                word[i] = 'h';
            }
            if (word[i] == 'i')
            {
                word[i] = 'v';
            }
            else if (word[i] == 'v')
            {
                word[i] = 'i';
            }
            if (word[i] == 'j')
            {
                word[i] = 'w';
            }
            else if (word[i] == 'w')
            {
                word[i] = 'j';
            }
            if (word[i] == 'k')
            {
                word[i] = 'x';
            }
            else if (word[i] == 'x')
            {
                word[i] = 'k';
            }
            if (word[i] == 'l')
            {
                word[i] = 'y';
            }
            else if (word[i] == 'y')
            {
                word[i] = 'l';
            }
            if (word[i] == 'm')
            {
                word[i] = 'z';
            }
            else if (word[i] == 'z')
            {
                word[i] = 'm';
            }
        }

        printf("Encrypted Word is : %s\n", word);
        printf("Try another word : ");
    }
}
