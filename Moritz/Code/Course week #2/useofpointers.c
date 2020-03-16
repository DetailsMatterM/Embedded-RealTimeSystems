#include <stdio.h>
#include  <stdlib.h>
void writearow( char row[][80]);

int main( void)
{
    char buffert[200][80];   // 200 Rows with 80 char per row
    char *ptr;	       // A common pointer 
     int i;

     for(i=0; i<3; i++){
             gets(buffert[i]);     // read in a row. No input control.
      }
	  puts(buffert[2]);
      ptr=buffert[1];
      puts(pekare);
      ptr+=2;
      puts(pekare);
	  writearow(buffert);  // Hard to understund
      return 0;
}

void writearow( char row[][80]){
	puts( row[2]);
}