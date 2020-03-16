/* ---- Demo program random array -----
  pointer_parameter.c
  Peter Lundin / 2016-02-03 
--------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>  /* Must have */
#define MAX 100

void dicefunction( int number, int tab[]);

int main()
{
  int i;
  int dicetab[7];                      // Array for dice number 1 to o6
  int *hpek=dicetab;
  printf("\n\n Pointer content in head is %p and dicetab address is %p", hpek, &dicetab);
  printf("\n\n Pointer address in head is %p ", &hpek);
  dicefunction(MAX, dicetab);
  /*
  for(i = 1 ; i < 7 ; i++ ){
         printf("\n The number of  %d   is # %d \n", i, dicetab[i]);
  }
  */
  return 0;
}
  
  
void dicefunction( int number, int *tab){
     int i, rand_val;
     srand( time(0));                 /* Init once */
     printf("\n\n Pointer content in func is %p ", tab); 
     printf("\n\n Pointer address in func is %p \n\n", &tab);
	 
     for(i = 0 ; i < number ; i++ ){
          rand_val = rand() % 6 + 1;  /*  1 <= rand_val <= 6 */
          tab[rand_val]++;
          
     }
}
  
  
