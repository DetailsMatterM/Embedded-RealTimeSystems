
#include <stdio.h
int main() {
    int c;
    char a [] = "You have entered 1!";
    char b [] = "You have entered 2!";
    char d [] = "You have entered 3!";
    char e [] = "You have entered 4!";
    char f [] = "You have entered 5!";

    printf("Enter anumber between 1 and 5\n");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf(a);
        break;
    
    case 2:
        printf(b);
        break;

    case 3:
        printf(d);
        break;

    case 4:
        printf(e);
        break;

    case 5:
        printf(f);
        break;
        
    default:
        printf("Please enter a number between 1 and 5");
        break;
    } 
    return 0;
}