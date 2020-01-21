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
    printf("Enter a word to encrypt it : \n");
    fgets(word, MAX, stdin);
    printf("word is : %s\n", word);

    for (int i = 0; i < 10; i++)
    {
        if (word[i] == 'a')
        {
            word[i] = 'n';
        }
    }

    printf("Encrypted Word is : %s\n", word);
}