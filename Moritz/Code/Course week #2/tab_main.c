//Filename tab_main.c
#include <stdio.h>
#include <stdlib.h>
#include "create_tab.h"
#define MAX 15
int exdemo=3;

int main (){
    int tab[MAX],n;
    create_tab(MAX,tab);
    for( n=0; n<MAX ; n++){
         printf("\n Number %d is %d ", n, tab[n]);
    }
	printf("\n exdemo= %d ", exdemo);
    return 0;
}