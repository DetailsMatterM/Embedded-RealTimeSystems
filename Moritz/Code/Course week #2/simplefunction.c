/* ---- Demo program simple function -----
  simplefunction.c
  Peter Lundin / 2013-01-27 
--------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

void swop( int x, int y);
void swop2( int* x, int* y);

int main()
{
  int a,b,temp=100;
  a=4,  b=10;
  
  
  swop( a,b);      // Passing by value
  printf("\n Interger a = %d and int b = %d ", a,b );
  swop2(&a, &b);    // Passing the adress to the pointer. ( 'Reference' )
  printf("\n Interger a = %d and int b = %d ", a,b );
  printf("\n Variabel temp= %d ", temp);
  return 0;
}

void swop( int x, int y){
     int temp;    // Local variables 
     temp=x;
     x=y;
     y=temp;            
}

void swop2( int* x, int* y){
     int temp;
     temp=*x;    
     *x=*y;     //  Assigning a with the pointer x
     *y=temp;
}
