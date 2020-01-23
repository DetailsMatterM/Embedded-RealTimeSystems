#include <stdio.h>
int main() {
    char input [20];
    char output [20];
    char alphabet [26];
    char c;
    int a = 0;
    for (c = 'a'; c <= 'z'; c++) {
        alphabet[a] = c;
        a++;
    }    
    for (c = 'a'; c <= 'm'; c++) {
        alphabet[a] = c;
        a++;
    } 
    char d;
    int i = 0;
    int alCount = 0;
    puts("Please enter a sentence");
    while((d = getchar()) != '\n') {
        input[i] = d;
        i++;
        for (int count = 0; count < 39; count++) {
            if(d == alphabet[count]) {
                output[alCount] = alphabet[(count + 13)];
                alCount++;
            }
        }
    }
    input[i] = '\0';
    output[alCount] = '\0';
    printf("%c", input);


    
    
    return 0;
}