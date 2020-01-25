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
    // following declaration would point to the 0th address in the array. this points to the whole array
    // int *pointer = array;
    int(*arrayPointer)[MAX] = array;
    for (i = 0; i < MAX; i++)
    {
        int temp;
        array[i] = rand() % 99;
        temp = array[i];

        //we can only save integers 1 - 99 so if theres a 0 , replace it.
        while (temp == 0)
        {
            temp = rand() % 99;
        }
        array[i] = temp;

        // This prints all saved integers with the temporarily saved integer and place in array
        //printf("%d # :  %d and temp %d\n", i, array[i], temp);
        int *intptr;
        intptr = &array[i];

        int *doublepointer;
        doublepointer = &array[i];

        printf("Integer value : %d\n Double value  : %f\n ****\n ", *intptr, (double)*doublepointer);
    }
    int size = sizeof(array);

    printf("The value  of the label array (address) is: %p \n", arrayPointer);
    printf(" First integer in the array is (%d): \n", array[0]);
    printf(" The size of an integer is (number of bytes) is %lu \n ", sizeof(int));
    printf("The size of the whole array is : %lu \n", array);
}
int main()
{

    randomizeNumbers();
    // checkForZeroes();
}