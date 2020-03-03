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
int search;

/*
 Rewrite the application in sortandfind_20.c
 so that each of the three main steps
    1.filling the array 
    2.sorting the array
    3.finding the value 
 given by the user are executed by 
 3 different threads and work as expected. 
 Clarify the function ofeach thread with a printf( )stating which of the 3 steps the thread is running.
 Possible output could be as below.*/

void *runner(void *param);
void *finding(void *param);
void *sorting(void *param);

int main()
{
    time_t t;
    //this is declaring a variable of type pthread_t - it is an integer used to identify the thread in the system.
    pthread_t tid;
    pthread_t find;
    pthread_t sort;
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
    pthread_join(tid, NULL);
    pthread_create(&sort, &attr, sorting, NULL);
    pthread_join(sort, NULL);
    printf("Enter value to find\n");
    scanf("%d", &search);
    pthread_create(&find, &attr, finding, search);
    pthread_join(find, NULL);

    return 0;
}

void *runner(void *param)
{
    printf("Executing runner thread\n");

    int c = 0, n = 0;

    for (c = 0; c < num_elems; c++)
    {
        for (n = 0; n < 1000; n++)
            ; // To delay a bit
        array[c] = rand() % max_value;
    }

    pthread_exit(0);
}

void *finding(void *param)
{
    printf("Executing finding thread\n");
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

    pthread_exit(0);
}

void *sorting(void *param)
{
    printf("Executing sorting thread\n");

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

    pthread_exit(0);
}
