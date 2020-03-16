

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define errno (*__errno_location ()) 


int main() 
{ 
      FILE* fileptr; 
      char filename[]= {"file1.txt"};
      char name[]="Peter";   
      // For getting an error erase the file fil1.txt and change mode to "r" , compile and run.
      if((fileptr = fopen(filename, "w")) == NULL){  
          printf("\n Could not be opened %s \n Errormessage: %s\n", filename, strerror(errno)); 
          return 1; 
      } 

      fprintf(fileptr, "Created by %s\n", name);
      fputs("Any text to the file now",fileptr);	  
      fclose(fileptr); 
      return 0; 
} 
