#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(){
    int randomArr [MAX];
    srand(time(NULL));

    int i = 0;
    while(randomArr[i] != NULL){
        randomArr[i] = rand() % 100;
        printf("Number %d: %d\n", i, randomArr[i]);                     //Print each index of randomArr
        i++;
    }
   
    printf("\nArray address: %pn\n", &randomArr);                       //Print Array address
    printf("First integer: %d\n", randomArr[0]);                        //Print First array index
    printf("Size of an integer: %ld bytes\n", sizeof(randomArr[i]));    //Print integer size
    printf("Size of randomArr: %ld bytes\n", sizeof(randomArr));        //Print randomArr size

    return 0;
}