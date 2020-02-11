#define MAX 10
#include <stdio.h>

int search_number(int number, int tab[], int size);

int search_number(int number, int tab[], int size)
{
    int flag = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (number == tab[i])
        {
            printf("number : %d exists in array!  index is %d \n", number, i);
            flag = 1;
            return i;
        }
    }

    if (flag == 0)
    {
        return -1;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int tab[], int number)
{
    int i, j;
    for (i = 0; i < number - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < number - i - 1; j++)
            if (tab[j] > tab[j + 1])
                swap(&tab[j], &tab[j + 1]);
}

/* Function to print an array */
void printArray(int tab[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

int main()
{
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);

    int test[MAX] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    search_number(number, test, MAX);

    bubbleSort(test, number);
    printf("Sorted array: \n");
    printArray(test, number);
    return 0;
}