// Skeleton for exercise nr 5 in WP 6 course DIT632.
// File skeleton_exerc_6_5.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Global buffer and corresponding counters.
char letter = 'a'; //the starting letter
#define MAX 10     //buffer size
unsigned short count = 0;
char buffer[MAX]; // circular buffer
int inpos = 0;    // index for next character to be put in buffer (put)
int outpos = 0;   // index for next character to be read ( fetch )

int signal;

void *put();
void *fetch();

int main() {
  pthread_t putT;
  pthread_t fetchT;
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  pthread_create(&putT, &attr, put, NULL);
  pthread_create(&fetchT, &attr, fetch, NULL);

  //int i;

  while (1) {
    for (size_t i = 0; i < 10000; i++) {}; // do some work
    printf("main is executing\n");
    
  }
}

void *put() {

  while (1) {
    
    if (pthread_mutex_lock(&count_mutex) == 0) {
      if (count == MAX){
        printf("Waiting for not full\n");
        pthread_cond_wait(&not_full, &count_mutex);
      }
      pthread_mutex_unlock(&count_mutex);
    }

    if (pthread_mutex_lock(&mutex) == 0) {
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

      printf("Buffer stored\n");

      pthread_mutex_unlock(&mutex);
    }

    if (pthread_mutex_lock(&count_mutex) == 0) {
      count++;
      pthread_mutex_unlock(&count_mutex);
      pthread_cond_signal(&not_empty);
    }
  }
}

void *fetch() {
  while (1) {
    
    if (pthread_mutex_lock(&count_mutex) == 0) {
      if (count == 0){
        printf("Waiting for not empty\n");
        pthread_cond_wait(&not_empty, &count_mutex);
      }
      pthread_mutex_unlock(&count_mutex);
    }

    if (pthread_mutex_lock(&mutex) == 0) {
      char output = buffer[outpos];
      if(outpos == MAX - 1) {
        outpos = 0;
      } else {
        outpos++;
      }

      printf("Buffer output %c\n", output);

      pthread_mutex_unlock(&mutex);
    }

    if (pthread_mutex_lock(&count_mutex) == 0) {
      count--;
      pthread_mutex_unlock(&count_mutex);
      pthread_cond_signal(&not_full);
    }
  }
}
