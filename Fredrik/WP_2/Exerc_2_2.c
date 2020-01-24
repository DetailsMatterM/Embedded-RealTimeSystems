/*====================================
File name: exerc_2_2.c
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
#define MAX 100
#include <stdio.h>

int array[MAX];
int i;

// checks if there are any zeros in the array. There shouldn't be
int checkForZeroes()
{
    int printedZeros = 0;
    for (i = 0; i < MAX; i++)
    {
        array[i] = rand() % (1 - 99);
        printf("%d # :  %d \n", i, array[i]);
        if (array[i] == 0)
        {
            printedZeros++;
        }
    }

    printf("0 printed %d times \n ", printedZeros);
}

int randomizeNumbers()
{

    //srand method allows us to create new random integers every time we run the program
    srand(time(0));
    for (i = 0; i < MAX; i++)
    {
        int temp;
        array[i] = rand() % 99;
        temp = array[i];

        while (temp == 0)
        {
            printf("hello");
            temp = rand() % 99;
        }
        array[i] = temp;

        printf("%d # :  %d and temp %d\n", i, array[i], temp);
    }
}
int main()
{
    randomizeNumbers();
    //checkForZeroes();
}