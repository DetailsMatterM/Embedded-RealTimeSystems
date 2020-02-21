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
  Serial.begin(9600);
  DDRB = B11111111; // configure as out port - rows
  DDRD = B00000000; // configure as in port - columns 
  
}

void loop()
{ 
	int number_pressed = check_key();
  if (number_pressed >= 0) {
  Serial.println(number_pressed, HEX);
  }
  
//unsigned char row = ~PORTB & B00001111; 
//unsigned char column = (~PIND >> 4) & B00001111;
//unsigned char key = row + column;

//Serial.println(row, BIN);  
//Serial.println(column, BIN); // zero if nothing is pressed
//Serial.println(key, DEC); 
//Serial.println("\n");
  
  
delay(1000); // Wait for 500 millisecond(s)
  
}

char check_key(){
  
 PORTB = B00000111; // set one row
  int number = PIND & B11110000;
  if (number == B01110000) {
 	return 0;
  } else if (number == B10110000) {
 	return 1;
  }  else if (number == B11010000) {
 	return 2;
  } else if (number == B11100000) {
 	return 3;
  }
    PORTB = B00001011; // set one row
  number = PIND & B11110000;
  if (number == B01110000) {
 return 4;
  } else if (number == B10110000) {
 	return 5;
  }  else if (number == B11010000) {
 	return 6;
  } else if (number == B11100000) {
 	return 7;
  }
  
  PORTB = B00001101; // set one row
  //return ~PIND;10000, BIN);
  number = PIND & B11110000;
  if (number == B01110000) {
 	return 8;
  } else if (number == B10110000) {
 	return 9;
  }  else if (number == B11010000) {
 	return 10;
  } else if (number == B11100000) {
 	return 11;
  }
      
  PORTB = B00001110; // set one row
  number = PIND & B11110000;
  if (number == B01110000) {
 	return 12;
  } else if (number == B10110000) {
 	return 13;
  }  else if (number == B11010000) {
 	return 14;
  } else if (number == B11100000) {
 	return 15;
  }
  return -1;
}
  