#define MAX 10
#include <stdio.h>

int search_number(int number, int tab[], int size);
void sort(int tab[], int number);
void printArray(int tab[], int size);

int main()
{
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);
    int test[MAX] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    int size = (sizeof(test) / sizeof(test[0]));

    search_number(number, test, MAX);

    printf("Unsorted Array:\n");
    printArray(test, size);

    printf("\nSorted Array\n");
    sort(test, size);
    printArray(test, size);

    return 0;
}

int search_number(int number, int tab[], int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (tab[i] == number)
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

void sort(int tab[], int number)
{
    int i, j, temp;
    for (i = 0; i < number; i++)
    {
        for (j = 0; j < number - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

/* Function to print an array */
void printArray(int tab[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d|", tab[i]);
    printf("\n");
}