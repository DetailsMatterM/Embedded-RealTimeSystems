/* ====================================
File name: exerc_2_5.c 
Date: 2020-02-06
Group nr 7
Members that contribute to the solutions
Fredrik Ullman
Mikael Köse Jansson
Moritz Denke

Demonstration code: [44544] Important , No code no exercise points !
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define MAXNUMBER 4

void create_random(int *tab);
void count_frequency(int *tab, int *freq);
void draw_histogram(int *freq);

int main() {
    int table [MAX], n;
    int frequency[MAXNUMBER];

    int *tab = &table;
    int *freq = &frequency;

    create_random(tab);
    count_frequency(tab, freq);
    draw_histogram(freq);
    return 0;
}

void create_random(int *tab) {
    srand(time(NULL));
    for(int i = 0; i < MAX; i++) {
        *tab = rand() % (MAXNUMBER + 1);
        tab++;
    }
}

void count_frequency(int *tab, int *freq) {
    int * tabTemp = tab;
    int n = 0;
    for(int i = 0; i <= MAXNUMBER; i++) {
        for(int y = 0; y < MAX; y++) {
            if (i == *tab){
                n++;
            }
            tab++;
        }
        *freq = n;
        freq++;
        n = 0;
        tab = tabTemp;
    }
}


void draw_histogram(int *freq) {
    for (int i = 0; i <= MAXNUMBER; i++) {
        if (*freq != 0) {
            if (i < 10) {
                printf("\n%d  ", i);
            } else {
                printf("\n%d ", i);
            }
            
            for (int y = 0; y < *freq; y++) {
                printf("%s", "x");
            }
        }
        freq++;
    }
}