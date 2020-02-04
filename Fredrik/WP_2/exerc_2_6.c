#include <stdio.h>
#define MAX 5

void initQue(int list[], int max);

int input(int list[], int number, int max);

int main()
{
    int que[MAX];
    initQue(que, MAX);
    input(que, 1, MAX);
    input(que, 2, MAX);
    input(que, 3, MAX);
    input(que, 4, MAX);
    input(que, 5, MAX);
    input(que, 8, MAX);

    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", que[i]);
    }
}

void initQue(int list[], int max)
{
    for (int i = 0; i < max; i++)
    {
        list[i] = -1;
        printf("%d ", list[i]);
    }
    printf(" \n ");
}

int input(int list[], int number, int max)
{
    for (int i = 0; i < max; i++)
    {
        if (list[i] == -1)
        {
            list[i] = number;
            return 1;
        }
        }
}
