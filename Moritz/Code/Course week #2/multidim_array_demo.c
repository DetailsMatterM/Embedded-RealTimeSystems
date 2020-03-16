// Demo ex multidimensionell array
// multidim_array_demo.c
// Peter Lundin

#include <stdio.h>
#include <stdlib.h>


int main (void){
    int matris[4][3] = { {0, 1, 2},       
                         {3, 4, 5},
                         {6, 7, 8},
                         {9, 10, 11}
                       };
    int row, col;
                       
    for ( row=0; row<4; row++){
       for (col =0; col < 3; col++){
           printf( "   %3d  " , matris[row][col]);
       }
       printf("\n");
    }
    
    return(0);
}
