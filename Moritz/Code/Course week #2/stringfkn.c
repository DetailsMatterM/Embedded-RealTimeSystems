/* ---- Demo program string funktion -----
  stringfkn.c
  Peter Lundin / 2013-01-27 
--------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stringcompare( const char* str1,  const char* str2);

int main()
{
  char user2[MAX];
  char username[]="Emil";  // Not after user2 in memory.
  
  puts("\nWrite your name : ");
  //gets(user2);         // Could give some problems due to input string length
  fgets(user2, MAX, stdin);
  user2[strlen(user2)-1]='\0'; //  take away '\n' befor the '\0' 
  puts(user2);
  putchar('\n');
  
   
  if ( stringcompare( username, user2))
         printf("\n Ok same \n" );
  else   
         printf("\n Not equal \n" );
  
  return 0;
}


int stringcompare( const char* str1, const char* str2){
    while (( *str1 == *str2 ) && *str1 !='\0'){ 
          str1++;
          str2++;      
    }
    
    if (*str1==*str2){ 
         return (1) ;
    } else return (0);
}
        
