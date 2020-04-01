int main(int argc, char**argv) {
    int i;
    unsigned char byte = 0;
    // We use - '0' to go from the ASCII representation of the numbers
    // to the actual integer value
    byte = byte + *argv[1] - '0'; //COmes in 4 and is actually 49 since we shift 
    byte = byte << 3;
    byte = byte + *argv[2] - '0';
    byte = byte << 2;
    byte = byte + *argv[3] - '0';
    byte = byte << 1;
    byte = byte + *argv[4] - '0';
    byte = byte << 1;
    byte = byte + *argv[5] - '0';

    printf("%x\n", byte);
    for(i=0; i< 8; i++) {
        if(((byte << i) & 0x80)) {
            printf("%d", 1);
        } else {
            printf("%d", 0);
        }
    }
}