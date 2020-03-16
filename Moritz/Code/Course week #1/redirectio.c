
/* redirectio.c     ---
Date 2013-01-23    
Peter Lundin        ----*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20
void clearstdin(void);

int main(void){
    
char c, text[MAX];
  int n=0;
  //clearstdin();   // Call this to be sure of empty buffer.
  fgets(text, MAX, stdin);

  // -----Alternative to fgets()-------------
 /* while(((c=getchar())!='\n') && n<MAX){
      text[n]=c; 
      n++;
  }
  text[n]='\0';
--------------------------------------*/

  puts(text);
  //gets(text);
  //puts(text);
  return(0);
}


// ------- Clear buffer ------
void clearstdin(void){
    char temp;
    while((temp=getchar())!='\n');
}
//-------------------------------------------------------------


      
      
        
