/* ---- Demo program Array of pointers -----
  arrayofpointers.c
  Peter Lundin / 2015-01-27 
--------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
void printlist( char *templist[]);

int main(void ){ 
  char *list[]={"Peter Lundin","Kalle","Oskar","Sven"};
  puts(list[2]);
  // Call of function printlist())
  printlist(list);
  return 0;
}
void printlist( char *templist[]){
	int n;
	for ( n=0;n<4;n++){
		puts(templist[n]);
	}
}

