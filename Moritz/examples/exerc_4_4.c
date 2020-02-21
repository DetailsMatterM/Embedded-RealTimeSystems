/* --- Macros preedefind for the compiler
DDRB Data direction register B
PORTB Outport B
PINB Inport B
DDRD Data direction register D
PORTD Outport D
PIND Inport D
*/

// PORT - write to
// PIN - read from

void setup()
{
  DDRB = B00000000; // configure as in port (8)
  DDRD = B11111111; // configure as out port (0 - 7)
  PORTB = B11111111; // set, so lights switch
  PORTD = B00000011; // initialise the forst two lights  
}

void loop()
{
    
  if (PINB & B00000001){ // AND operator, will be 1 if bit is 1 and 0 if bit is 0
  	if (PORTD & B10000000) { // true in both rotate cases
      	PORTD <<= 1; // shift 1 bit to the right
    	PORTD |= B00000001; // sets the first bit
    } else {
    	PORTD <<= 1; // shift 1 bit to the right
    }
  }
  
  delay(500); // Wait for 500 millisecond(s)

}