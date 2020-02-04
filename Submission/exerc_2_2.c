#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50
int main() {
    srand(time(NULL));
    int random [MAX];
    int * pointer = &random;
    int i;
    for (i = 0; i < MAX; i++) {
        random[i] = (rand() % (99 - 1 + 1)) + 1;
    }
    printf("\n%s", "The value of the label array(address) is: ");
    printf("%pn", &random);
    printf("\n%s", "First integer in the array is (array[0]) : ");
    printf("%d", random[0]);
    printf("\n%s", "The size of an integer (number of bytes) is : ");
    printf("%zu", sizeof(i));
    printf("\n%s", "The size of the whole array is: ");
    printf("%zu", sizeof(random));

    for (int y = 0; y < MAX; y++) { 
        printf("\n Int: %d", *pointer);
        printf(" Double: %f", (double)*pointer);
        pointer++;
    }
    
    return 0;
}