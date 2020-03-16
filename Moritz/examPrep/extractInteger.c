#include <stdio.h>
#include <stdlib.h>
//27290
void extract(unsigned char code);

int main () {
    char engine_on = 1;
    char gear_pos = 1;
    char key_pos = 0;
    char brake1 = 0;
    char brake2 = 1;
    unsigned char code = (engine_on << 6) & (gear_pos << 5) & (key_pos << 4);
    extract(code);
}
    

void extract(unsigned char code) {
    int result = (code >> 4) & 0x70; 
    printf("%d", result);
}