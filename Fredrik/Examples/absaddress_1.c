
// Program absadr_2.c   Bitmanagement

#define REG8(x) *((unsigned char *)(x))
#define BIT7       0x80
#define PORTA      0x0402 // OUT-port 
#define PORTB      0x0400 // IN-port

int main(void){
  unsigned char instatus;
  while(1){
    instatus=REG8(PORTB);
    if (REG8(PORTB)& BIT7) {
         REG8(PORTA)=(REG8(PORTB)) | 0x10 ;
         //REG8(PORTA)=instatus+128;
    } else {
         REG8(PORTA)=instatus;
    }
  }
  return(0);
}
