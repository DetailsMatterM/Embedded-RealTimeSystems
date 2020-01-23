#include <stdio.h>
#define MAX 40

int main() {
    char input[MAX];
    char c;
    int i = 0;
    int counter = 1;
    puts("Please enter a sentence");
    while((c = getchar()) != '\n') {
        input[i] = c;
        i++;
        if(c == ' '){
            counter++;
        }
    }    
    printf("%d", counter);
    return 0;
}