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
#define MAX 200
char word[MAX];
void copyStringManually()
{
    char savedWord[MAX];
    savedWord[MAX];
    for (int i = 0; i < MAX + 1; i++)
    {
        savedWord[i] = word[i];
    }

    printf("printed from copyString : %s", savedWord);
}

int readFile()
{
    // reading input from a text file
    FILE *fp;
    char str[MAX];
    char *filename = "/home/fredrik/Documents/SEM/DIT632Development_of_embedded_and_Real_Time_Systems/Embedded-RealTimeSystems/Fredrik/WP_2/myfile.txt";

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 1;
    }
    while (fgets(str, MAX, fp) != NULL)
    {
        printf("%s \n", str);
        fclose(fp);
        return 0;
    }
}

int copyStringAutomatically()
{
    char saved[MAX];
    printf("Type something : \n");
    fgets(word, MAX, stdin);

    // a ) copy the string to another string
    strcpy(saved, word);
    printf("printed from strcpy() : %s", saved);
}

int main()
{
    //reads input from text file
    readFile();

    // a ) copy from library function
    copyStringAutomatically();

    // b  ) copy the string manually
    copyStringManually();
}