// multi_array_demo_2.c
#include <stdio.h>
#include  <stdlib.h>
void printtab ( int tab[][3]);
int main (void){
    int matris[4][3] = { {0, 1, 2},       
                         {3, 4, 5},
                         {6, 7, 8},
                         {9, 10, 11}
                       };
printtab( matris);
}
//----------------------------------
void printtab ( int tab[][3]){  
int row, col;                 
    for ( row=0; row<4; row++){
       for (col =0; col < 3; col++){
           printf( "   %3d  " , tab[row][col]);
       }
       printf("\n");
    }
}