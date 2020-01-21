/*====================================
File name: exerc_1_2.c (or cpp)
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
#define MAX 100

int main()
{

    //everytime theres a space it counts it as a new word, so "?" would count as a word.. perhaps theres a nice fix for all these edge - cases
    char letters[MAX];
    int counter = 1;
    fgets(letters, MAX, stdin);
    printf("string is: %s\n", letters);

    for (int i = 0; i < MAX; i++)

    {
        if (letters[i] == ' ')
        {
            counter++;
        }
    }
    printf("Amount of words in the sentence :\n %d", counter);

    return 0;
}
