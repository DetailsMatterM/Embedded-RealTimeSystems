/* ====================================
File name: exerc_3_2.c (or cpp)
Date: 2019-02-13
Group Number:07
Members that contributed:
Fredrik Ullman
Mikael Köse Jansson
Moritz Denke
Demonstration code: [47559] Important !
====================================== */
//
#include <stdio.h>
#define TESTNUMBER -67
int search_number (int number, int tab [], int size);
void sort (int number, int tab[]);

int main () {
    int test [] = {-7, -67};
    int size = (sizeof(test)/sizeof(test[0]));
    int a = search_number(TESTNUMBER, test, size);
    if (a != -1) {
        printf("Number %d is found at index %d\n", TESTNUMBER, a);
    } else {
        printf("Number is not part of the array\n");
    }
    
    printf("Unsorted Array:\n");
    for(int j = 0; j < size; j++) {
        printf("%d|", test[j]);
    }
    printf("\nSorted Array\n");
    sort(size, test);   
    for (int j = 0; j < size; j++) {
        printf("%d|", test[j]);
    }
}

int search_number (int number, int tab[], int size) {
    for (int i = 0; i < size; i++) {
        if (tab[i] == number) {
            return i;
        }
    }
    return -1;
}

void sort (int number, int tab[]) {
    int i, j, temp;
    for (i = 0; i < number; i++) {
        for ( j = 0; j < number - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}
