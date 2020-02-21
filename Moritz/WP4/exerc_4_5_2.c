#include <avr/io.h>
#include <util/delay.h>

byte a = B01110000;
byte b = B10110000;
byte c = B11010000;
byte d = B11100000;
void setup() {
    Serial.begin(9600); // If use of Serial monitor
    DDRB = B11111111;   // configure as out port - rows
    DDRD = B00000000;
}

int last = -1;
void loop() {
    delay(10);
    int pressed = getKeypadInput();
    if (pressed == last) {
   	    return; 
  	}
    if (pressed >= 0) {
        Serial.println(pressed, HEX);
    }
    last = pressed;
}

int checker(int number, int identifier) {
    if (number == a) {
        return identifier;
    }
    else if (number == b) {
        return (identifier + 1);
    }
    else if (number == c) {
        return (identifier + 2);
    }
    else if (number == d) {
        return (identifier + 3);
    }
    else {
        return -1;
    }
}

char getKeypadInput() {
    PORTB = B00000111;
    int number = PIND & B11110000;
    int check = checker(number, 0);
    if (check != -1) {
        return check;
    }

    PORTB = B00001011; 
    number = PIND & B11110000;
    check = checker(number, 4);
    if (check != -1) {
        return check;
    }

    PORTB = B00001101;
    number = PIND & B11110000;
    check = checker(number, 8);
    if (check != -1) {
        return check;
    }

    PORTB = B00001110;
    number = PIND & B11110000;
    check = checker(number, 12);
    if (check != -1) {
        return check;
    }

    return -1;
}