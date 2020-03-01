// Program for exercise 6.2alt in DIT632
// Version 2020-02-12
// File : sortandfind_20.c
// **************************************
// to run a program with pthread : gcc program.c -o program -lpthread and then the normal run command "./program"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define num_elems 200
int array[200];
int max_value;

void *runner(void *param);

int main()
{
    time_t t;
    //this is declaring a variable of type pthread_t - it is an integer used to identify the thread in the system.
    pthread_t tid;
    //this is setting attributes in the threads, which essentially means that we
    //change behaviour in the thread. not so commonly used . https://users.cs.cf.ac.uk/Dave.Marshall/C/node30.html
    pthread_attr_t attr;

    srand((unsigned)time(&t));
    pthread_attr_init(&attr);

    printf("Enter max value\n");
    scanf("%d", &max_value);
    //this function creates a thread , takes 4 arguments.
    /*
        1. pointer to thread_id. 
        2. specifies attributes. if null then default attributes
        3. name of function to be executed for the thread to be created
        4. used to pass arguments to the function, in our case "runner" function.
        */
    pthread_create(&tid, &attr, runner, NULL);
    //blocks threads, its equivalent to "wait()" for processes.
    pthread_join(tid, NULL);

    int c, d, swap;

    for (c = 0; c < num_elems; c++)
    {
        for (d = 0; d < num_elems - c - 1; d++)
        {
            if (array[d] > array[d + 1])
            {
                swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }

    int search;
    printf("Enter value to find\n");
    scanf("%d", &search);

    int first = 0;
    int last = num_elems - 1;
    int middle = (first + last) / 2;
    int n;
    for (n = 0; n < num_elems; n++)
    {
        printf("\n %d", array[n]);
    }

    while (first <= last)
    {
        if (array[middle] < search)
            first = middle + 1;
        else if (array[middle] == search)
        {
            printf("\n %d found at location %d.\n", search, middle + 1);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last) / 2;
    }
    if (first > last)
        printf("\n Not found! %d is not present in the list.\n", search);

    return 0;
}

void *runner(void *param)
{
    int c = 0, n = 0;

    for (c = 0; c < num_elems; c++)
    {
        for (n = 0; n < 1000; n++)
            ; // To delay a bit
        array[c] = rand() % max_value;
    }

    pthread_exit(0);
}
