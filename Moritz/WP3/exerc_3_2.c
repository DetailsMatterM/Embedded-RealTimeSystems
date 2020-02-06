#include <stdio.h>
#define TESTNUMBER 23
#define MAXVALUE 2147483647
int search_number (int number, int tab [], int size);
void sort (int number, int tab[]);

int main () {
    int test [] = { 1,2,34,5,67,3,23,12,13,10};
    int size = (sizeof(test)/sizeof(test[0]));
    int a = search_number(TESTNUMBER, test, size);
    printf("%d\n", a);

    //implement for loop. Arguments are number standing for the intex from which we are still searching.
    for(int j = 0; j < size; j++) {
        printf("%d,", test[j]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        sort(i, test);
    }
    for(int j = 0; j < size; j++) {
        printf("%d,", test[j]);
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
    int tempmin = MAXVALUE;
    int minIndex;
    for (int i = number; i < (sizeof(tab)/sizeof(tab[0])); i++) {
        if (tab[i] <= tempmin) {
           tempmin = tab[i]; 
           minIndex = i;
        }
    }
    if (tempmin != MAXVALUE) {
        tab[minIndex] = tab[number];
        tab[number] = tempmin;
    }
    
}