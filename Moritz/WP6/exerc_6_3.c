#define ML13_Status 0x0B10
#define ML13_Control 0x0B00

int objectWithinRange = 1;
char status = ML13_Status;
char control = ML13_Control;

void main()
{
    int failsafe = 0;
    while(failsafe == 0) {
        failsafe = doorLoop();
    }
    return 0;
}

int doorLoop() {
    char a = 1 ; 
    
    if (((control >> 2) & 0x01) == 0x0B01)  {
        status = a << 1;
        printf("Hello");
    }
   // delay(10000);
    return 1;
}