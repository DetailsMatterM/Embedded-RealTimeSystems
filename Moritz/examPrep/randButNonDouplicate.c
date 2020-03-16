#include <time.h>
#include <stdlib.h>
#define MAX 10

void unique_random_list(int list[], int num) {
    srand(time(NULL));
    int* randp = &list;
    for (int i = 0; i < num; i++) {
        *randp = rand() % MAX;
        while (*randp <= 0) {
            *randp = rand() % MAX;
        }
    }
}