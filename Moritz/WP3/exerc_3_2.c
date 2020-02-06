#include <stdio.h>
#define testNumber 23

int search_number (int number, int tab [], int size);

int main () {
    int test [] = { 1,2,34,5,67,3,23,12,13,10};
    int a = search_number(testNumber, test, (sizeof(test)/sizeof(test[0])));
    printf("%d", a);
}

int search_number (int number, int tab[], int size) {
    for (int i = 0; i < size; i++) {
        if(tab[i] == number) {
            return i;
        }
    }
    return -1;
}