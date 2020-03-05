// Skeleton for exercise nr 5 in WP 6 course DIT632.
// File skeleton_exerc_6_5.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

// Global buffer and corresponding counters.
char letter = 'a'; //the starting letter
#define MAX 10     //buffer size
unsigned short count = 0;
char buffer[MAX]; // circular buffer
int inpos = 0;    // index for next character to be put in buffer (put)
int outpos = 0;   // index for next character to be read ( fetch )

void *put();
void *fetch();

int main()
{

    //set up and run two threads, put and fetch
    //after setting up threads, run loop.
    pthread_t putTid;
    pthread_t fetchTid;

    pthread_create(&putTid, NULL, put, NULL);
    // pthread_create(&fetchTid, NULL, fetch, NULL);
    //put : create chars a -z and store in buffer array.
    //for every char stored call conditional signal
    //fetch : fetch the char i first position and printf.

    int i = 0;

    while (1)
    {
    }
}

void *put()
{
    while (1)
    {

        for (int i = 0; i < MAX; i++)
        {
            buffer[i] = letter;
            printf("i#: %d %c \n", i, buffer[i]);
            letter++;
        }
        return 0;
    }
}

void *fetch()
{
    while (1)
    {
    }
}
