/*
 *  File    : arr_basic_demo.c 
 *  Program : Move elements to the right
 *  Peter Lundin
 */
#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int main()
{
  int arr[MAX] = { 1,2,3,4,5 };     // Allocate memory and stores a value for each 
  int arr_copy[MAX];                // Allocate memory for 5 int's, no values
  int tmp, i;
  // Rotate a position to the left
  tmp = arr[0];
  for( i = 0 ; i < MAX-1 ; i++ ){ 
    arr[ i ] = arr[ i + 1 ];
  }
  arr[MAX-1] = tmp;
  // copy arr to arr_copy

  for( i = 0 ; i < MAX ; i++ ){
    arr_copy[i]=arr[i];   
    printf("%d ", arr[i] );
  }
  return 0;
}
