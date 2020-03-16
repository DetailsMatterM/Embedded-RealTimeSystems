// test 

#include <stdio.h>
#include <stdlib.h>

#define DEBUG

#ifdef DEBUG
#define debug(s) printf("\n %s ", s);
#else
#define debug(s) printf("\n Else ..%s \n", s);
#endif

int main(){
     int a=3;
     #ifdef DEBUG
         printf("a is %d \n",a);
     #endif
     debug("Reached here. \n");
     system("PAUSE");
     return (0);
 }
     
