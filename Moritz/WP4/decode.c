int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Type : exerc_4_1.exe engine_on parameter, gear_pos parameter, key_pos parameter, brake 2 parameter and brake1 parameter\n");
    } else {

        unsigned char a = argc[1];








        char engine_on = atoi(argv[1]);
        char gear_pos = atoi(argv[2]);
        char key_pos = atoi(argv[3]);
        char brake1 = atoi(argv[4]);
        char brake2 = atoi(argv[5]);
        unsigned char b = (engine_on << 7) ^ (gear_pos << 4) ^ (key_pos << 2) ^ (brake2 << 1) ^ brake1;
        
        for (int i = 7; 0 <= i; i--) {
            printf("%c", (b & (1 << i)) ? '1' : '0');
        }
    }   
}
    