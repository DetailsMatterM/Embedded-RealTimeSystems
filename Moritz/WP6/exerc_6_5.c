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
#define MAX 5     //buffer size
unsigned short count = 0;
char buffer[MAX]; // circular buffer
int inpos = 0;    // index for next character to be put in buffer (put)
int outpos = 0;   // index for next character to be read ( fetch )



void *put();
void *fetch();

int main() {
  pthread_t putT;
  pthread_t fetchT;
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  pthread_create(&putT, &attr, put, NULL);
  pthread_create(&fetchT, &attr, fetch, NULL);

  while (1) {
    printf("Main is executing\n");
    for (int i = 0; i < 200000; i++);
  }
}

void *put() {

  while (1) {
    // Make sure a lock is successfully obtained
    // Otherwise, exit the thread (errored)
    if (pthread_mutex_lock(&count_mutex) != 0) {
      exit(1);
    }

    // Wait for the buffer to not be full
    if (count == MAX) {
      printf("Waiting for not full\n");
      pthread_cond_wait(&not_full, &count_mutex);
    }

    // Put a character into the buffer and increment
    // to the next letter and position in the buffer
    buffer[inpos] = letter;
    letter++;

    if (letter > 'z') {
      letter = 'a';
    }

    if (inpos == MAX - 1) {
      inpos = 0;
    } else {
      inpos++;
    }

    // Print that we put something into the buffer
    printf("Buffer stored\n");

    // Increment the counter of data to process
    count++;

    // Send the not empty signal
    if (count == 1) {
      pthread_cond_signal(&not_empty);
    }

    // Make sure a lock is successfully released
    // Otherwise, exit the thread (errored)
    if (pthread_mutex_unlock(&count_mutex) != 0) {
      exit(1);
    }

    // Do shitty random wait that we don't know why it's needed
    for (int i = 0; i < 100000; i++);
  }
}

void *fetch() {
  while (1) {
    // Make sure a lock is successfully obtained
    // Otherwise, exit the thread (errored)
    if (pthread_mutex_lock(&count_mutex) != 0) {
      exit(1);
    }

    // Wait for the buffer to have something in it
    if (count == 0) {
      printf("Waiting for not empty\n");
      pthread_cond_wait(&not_empty, &count_mutex);
    }

    // Take out a character from the buffer and increment to the next
    char output = buffer[outpos];
    if (outpos == MAX - 1) {
      outpos = 0;
    } else {
      outpos++;
    }

    // Print what we just got out of the buffer
    printf("Buffer output %c\n", output);

    // Decrement the counter of data to process
    count--;

    // Send the not full signal
    if (count == MAX - 1) {
      pthread_cond_signal(&not_full);
    }

    // Make sure a lock is successfully released
    // Otherwise, exit the thread (errored)
    if (pthread_mutex_unlock(&count_mutex) != 0) {
      exit(1);
    }

    // Do shitty random wait that we don't know why it's needed
    for (int i = 0; i < 100000; i++);
  }
}
