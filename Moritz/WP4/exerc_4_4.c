#include <avr/io.h>
#include <util/delay.h>
//DDRB  Data direction register B
//PORTB Outport B
//PINB  Inport B
//DDRD  Data direction register D
//PORTD Outport D
//PIND  Inport D

void setup() {
  pinMode(PORTB, INPUT);
  PORTD = B00000011;
  PORTB = B00000001;
  PINB = B00000001;
  DDRD = B11111111;
  DDRB = B00000000;
  PINB = PB0;
}

void loop() {
  if (PINB != B00000001) {
  
    delay(1000);
    PORTD = PORTD << 1;
    if (PORTD == B11000000) {
        delay(1000);
        PORTD = B00000011;
    }  

  }
}