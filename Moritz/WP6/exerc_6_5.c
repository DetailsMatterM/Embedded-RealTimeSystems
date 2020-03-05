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
//void *fetch();

int main() {
  pthread_t putT;
  //pthread_t fetchT;
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  pthread_create(&putT, &attr, put, NULL);
  //pthread_create(&fetchT, &attr, fetch, NULL);

  //int i;

  while (1) {
    //printf("main is executing");
    
  }
}

void *put() {

  while (1) {
    int mute;
    if ((mute = pthread_mutex_lock(&mutex)) == 0) {
      pthread_cond_signal(&not_empty);
      buffer[inpos] = letter;
      printf("%c", letter);
      letter++;
      if (letter > 'z') {
        letter = 'a';
      }
      if(inpos == MAX - 1) {
        inpos = 0;
      } else {
        inpos++;
      }
      count++;
      pthread_mutex_unlock(&mutex);
    }
  }
}

void *fetch() {
  while (1) {
      if (outpos < inpos) {
        if(outpos == MAX - 1) {
          outpos = 0;
        } else {
          outpos++;
        }
        count--;
      }
  }
}
