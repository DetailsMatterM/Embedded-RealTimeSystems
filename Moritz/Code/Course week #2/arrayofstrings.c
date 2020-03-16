/* ---- Demo program Array of pointers -----
  arrayofstrings.c
  Peter Lundin / 2019-01-27 
--------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void ){
  char buffer[200][80];
  char *ptr;
  int i;
  for ( i=0; i<3;i++){
	  fgets(buffer[i],80,stdin);
  }
  ptr=buffer[1];
  puts(row);
  puts(buffer[1]);
  ptr+=2;
  puts(ptr);
  return 0;
}

