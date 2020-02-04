#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER 20

void create_random( int *tab );             // Use pointer to fill the table
void count_frequency(int *tab, int *freq ); // Use pointer
void draw_histogram(int *freq );            // Use pointer

int main(){
    int table[MAX], n ;
    int *tab = &table;
    
    int frequency[MAXNUMBER];
    int *freq = &frequency;
}

void create_random(int *tab){
    int i;
    for(i = 0; i < MAX; i++) {
        *tab = rand() % MAXNUMBER;
       
        tab++;
    }
}

void count_frequency(int *tab, int *freq){
    
}