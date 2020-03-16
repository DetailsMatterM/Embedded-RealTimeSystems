// ----------------------------------------------------------------------------------------
#define MAX 100
#define PORTA 0x0400 // IN-port
#define PORTB 0x0402 // IN-port
#define REG8(x) *(( unsigned char *) (x))
int readValues ( unsigned char* tab );
void delayTime( int n ); // Delay n seconds can be used.
int main(void){
unsigned char table[MAX];
int nr=0;
// ---------------------------------------
………
nr=readValues(table);
……..
……..
}
//-----------------------------------------
return(0);
}

int readValues( unsigned char* tab ){
    int i = 0;
    while (((PORTA << 7) & 0x01 == 1) && i < MAX) {
        
    }
/* -----------------------------------------------------------------------
Reads inport PORTA every second as long as
bit 7 on PORTB is set (1) and the number of readings are less than MAX.
The values of bit 7 down to 4 should be cleared before saving the value in the Array tab[].
The function shall return the actual number of read values.
For 1 second delay call delayTime(1);
-----------------------------------------------------------------*/
}