/* ====================================
File name: exerc_4_5.c 
Date: 2019-02-20
Group Number:07
Members that contributed:
Fredrik Ullman
Mikael Köse Jansson
Moritz Denke
Demonstration code: [26422] Important !
====================================== */
const byte rows = 4;
const byte columns = 4;
const byte Output[rows] = {11, 10, 9, 8}; 
const byte Input[columns] = {7, 6, 5, 4}; 

byte getKeypadInput() {
    static bool no_button_pressed = 0;
    for (byte c = 0; c < columns; c++) {
        if (digitalRead(Input[c]) == LOW) {
            break;
        }
        if (c == (columns - 1)) {
            no_button_pressed = 1;
        }
    }
    if (no_button_pressed == 1) {
        for (byte i = 0; i < rows; i++) {
            digitalWrite(Output[i], LOW);
        } 
        for (byte c = 0; c < columns; c++) {
            if (digitalRead(Input[c]) == LOW) {
                for (byte r = 0; r < rows; r++) {
                    digitalWrite(Output[r], HIGH);
                    if (digitalRead(Input[c]) == HIGH) {
                        for (byte i = 0; i < rows; i++) {
                            digitalWrite(Output[i], LOW);
                        }
                        return r * 4 + c;
                    }
                }
            }
        }
    }
    return 50;
}

void setup() {
    Serial.begin(9600);
    for (byte i = 0; i < rows; i++) {
        pinMode(Output[i], OUTPUT);
    }
}

char toHex(byte num) {
    switch (num) {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    default:
        return '?';
    }
}


char last = '?';
void loop() {
    delay(10);
    const char pressed = toHex(getKeypadInput());
  	if (pressed == last) {
   	    return; 
  	}
    if (pressed != '?') {
        Serial.println(pressed);
    }
    last = pressed;
}