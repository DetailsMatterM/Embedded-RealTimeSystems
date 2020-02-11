#define MAX 10
#include <stdio.h>

int search_number(int number, int tab[], int size);

int main()
{
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);

    int test[MAX] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    search_number(number, test, MAX);
}

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