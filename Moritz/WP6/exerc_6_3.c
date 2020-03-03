#define ML13_Status 0x0B10
#define ML13_Control 0x0B00

int objectWithinRange = 1;
char control = ML13_Status;
void main()
{
    
}

int doorLoop() {
    char a = 1 ; 
    
    if (control == 0x0B00 && objectWithinRange == 1) {
        control = a << 1;
    }
}