int main() {
    int i;
    unsigned char byte = 0;
    byte = byte + 1 - '0';
    byte = byte << 3;
    byte = byte + 2 - '0';
    byte = byte << 2;
    byte = byte + 1 - '0';
    byte = byte << 1;
    byte = byte + 1 - '0';
    byte = byte << 1;
    byte = byte + 1 - '0';

    printf("%x\n", byte);
    for(i=0; i< 8; i++) {
        if(((byte << i) & 0x80)) {
            printf("%d", 1);
        } else {
            printf("%d", 0);
        }
    }
}