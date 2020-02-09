#include <stdio.h>
#define TESTNUMBER 34
int search_number (int number, int tab [], int size);
void sort (int number, int tab[]);

int main () {
    int test [] = { 1,2,34,5,67,3,23,12,13,10};
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
