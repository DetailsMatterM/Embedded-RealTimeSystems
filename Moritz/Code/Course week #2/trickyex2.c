#include <stdio.h>
#include <stdlib.h>

int main(){
   
  int a=260;    // 137 alt 260
  char *ptr;
  ptr=(char *) &a;
  //printf("Intpek is %p and charpek is %p", &a, ptr);
  printf("%d", *ptr++);
  printf("\n %d", *ptr);
  
}