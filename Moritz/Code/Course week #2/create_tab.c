// Filename create_tab.c
#include <stdlib.h>
#include <time.h>

#define MAX 100

void create_tab( int quantity, int temp_tab[]){
   int n;
   extern int exdemo; // Not extern just local exdemo 
   srand(time(0));
   exdemo++;  //inc exdemo in tab_main.c module if extern here
   for( n=0; n< quantity; n++){
        temp_tab[n]=rand()% MAX;
   }
}
