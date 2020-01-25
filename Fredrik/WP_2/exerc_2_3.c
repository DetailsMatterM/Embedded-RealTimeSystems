/*====================================
File name: exerc_2_3.c
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
#include <stdlib.h>
#define MAX 50

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("Type : %s firstword secondword \n", argv[0]);
        return 1;
    }
    printf("First word : %s , Second word : %s \n", argv[1], argv[2]);
    return 0;
}
