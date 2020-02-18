#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
    char engine_on = 1;
    char gear_pos = 2;
    char key_pos = 2;
    char brake1 = 1;
    char brake2 = 1;
    unsigned char b = (engine_on << 7) ^ (gear_pos << 4) ^ (key_pos << 2) ^ (brake2 << 1) ^ brake1;
    
    for (int i = 7; 0 <= i; i--) {
        printf("%c", (b & (1 << i)) ? '1' : '0');
    }
    // if (argc < 5 || argc > 6) {
    //     printf("Type : exerc_4_1.exe engine_on parameter, gear_pos parameter, key_pos parameter, brake 2 parameter and brake1 parameter\n");
    // } else {
    //     //printf("%c", argv[1][0]);
    //     char engine_on = atoi(argv[1]);
    //     //printf("%c", argv[2][0]);
    //     char gear_pos = atoi(argv[2]);
    //     //printf("%c", argv[3][0]);
    //     char key_pos = atoi(argv[3]);
    //     //printf("%c", argv[4][0]);
    //     char brake1 = atoi(argv[4]);
    //     //printf("%c", argv[5][0]);
    //     char brake2 = atoi(argv[5]);
    //     unsigned char b = (engine_on << 7) ^ (gear_pos << 4) ^ (key_pos << 2) ^ (brake2 << 1) ^ brake1;
    //     for (int i = 7; 0 <= i; i--) {
    //     printf("%c", (b & (1 << i)) ? '1' : '0');
    //     }
    // }   
}
    