#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER 20

// ------Function declaration   ----------
// Use pointer to fill the table
void create_random(int *tab);
void count_frequency(int *tab, int *freq); // Use pointer
void draw_histogram(int *freq);            //  Use pointer
int main(void)
{

    int table[MAX];
    int *tblptr = table;
    int n;
    int frequency[MAXNUMBER];
    create_random(table);
    count_frequency(table, frequency);

    for (int i = 0; i < MAX; i++)
    {
        printf("%d#: %d \n", i, tblptr);
        tblptr++;
    }
}

void create_random(int *tab)
{
    srand(time(0));

    for (int i = 0; i < MAX; i++)
    {
        *tab = rand() % MAXNUMBER;
        tab++;
    }
}
void count_frequency(int *tab, int *freq)
{
    int tempArr[MAX];
    int *ptr = tempArr;
    *ptr = *tab;

    for (int i = 0; i < MAX; i++)
    {
        if (*ptr == *tab)
        {

            *freq = *ptr;
            //printf("oh snap theyre equal, saved into freq arr! (ptr = %d) %d \n", *ptr, *freq);
        }

        //  printf("%d#:  %d -- %d\n", i, *ptr, *tab);
        tab++;
    }
}