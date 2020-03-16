#include <stdio.h>
#include <stdlib.h>
void func_1(int list[]);
int main(void){
  int tab[]={1,2,3,4,5,6};
  printf("\n In main number is %d ", tab[3]);
  func_1(tab);
  }
  
 void func_1(int list[]){
   int m=3;
   printf("\n In func number is %d ", list[3]);
   list++;
   printf("\n In func number now is %d ", list[3]);
 }
   