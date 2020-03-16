// Test of getchar/scanf and some more...
// DIT632 2020

#include <stdlib.h>
#include <stdio.h>
#define MAX 10
void clearstdin(void);

int main(void){
int n=0;
char c;
char text[MAX];
printf("\n Give a text:   ");

 while( (c=getchar())!='\n'){
   text[n]=c;
   n++;
 }
 text[n='\0'];
 printf("\n Text is as follows: %s\n ", text);
 
 printf("\n Give a new text:  ");
 scanf("%5s", text); 
  
 printf("\n New text is as follows: %s\n ", text);
 //fflush(stdin);
 clearstdin();
 gets(text);
 puts(text);
return (0);

}

void clearstdin(void){
    char temp;
    while((temp=getchar())!='\n');
}
