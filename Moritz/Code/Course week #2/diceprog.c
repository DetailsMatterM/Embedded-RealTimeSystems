/* ---- Demo program random array -----
  diceprog.c
  Peter Lundin / 2019-01-27 
--------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>  /* Must have */
#define MAX 10

void dicefunction( int number, int tab[]);

int main()
{
  int i;
  int dicetab[MAX];                      // Array for MAX dice number
  for(i = 0 ; i < MAX ; i++ ){
         dicetab[i]=0;                   // Clear the numbers
  }
  
  dicefunction(MAX, dicetab);
  
  for(i = 1 ; i < 7 ; i++ ){
         printf("\n The number of  %d   is # %d \n", i, dicetab[i]);
  }
  system("PAUSE");
  return 0;
}
  
  
void dicefunction( int number, int *tab){
     int i, rand_val;
     srand( time(0));                 /* Init once */
         
     for(i = 0 ; i < number ; i++ ){
          rand_val = rand() % 6 + 1;  /*  1 <= rand_val <= 6 */
          tab[rand_val]++;
          
     }
}
  
  
