#include <stdio.h>
#include <string.h>

#define MAX 20

int main(){
    char palStr[MAX];
    char revPalStr[MAX];

    printf("Type that shit: \n");
    gets(palStr);

    strcpy(revPalStr, palStr);          //Copy string
    strrev(revPalStr);                  //Reverse string
    strcmp(palStr, revPalStr);          //Compare both strings

    if(strcmp(palStr, revPalStr) != 0){
        printf("\n%s : That shit is no palindrome", palStr);
    }else
    {
        printf("\n%s : That shit is a palindrome", palStr);
    }
    

    return 0;
}