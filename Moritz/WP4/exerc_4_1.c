#include <stdio.h>
int main () {
    char engine_on = 1;
    char gear_pos = 2;
    char key_pos = 2;
    char brake1 = 1;
    char brake2 = 1;

    unsigned char b = (engine_on << 7) ^ (gear_pos << 4) ^ (key_pos << 2) ^ (brake2 << 1) ^ brake1;
//  //
    for (int i = 7; 0 <= i; i--) {
        printf("%c", (b & (1 << i)) ? '1' : '0');
    }