const byte rows = 4;
const byte columns = 4;
const byte Output[rows] = {11, 10, 9, 8}; // Array of pins used as output for rows of keypad
const byte Input[columns] = {7, 6, 5, 4}; // Array of pins used as input for columns of keypad

byte getKeypadInput() {
    // Loop through all of the colums and check their
    // voltages to see if any button is being pressed
    static bool no_button_pressed = 0;
    for (byte c = 0; c < columns; c++) {
        if (digitalRead(Input[c]) == LOW) {
            break;
        }
        if (c == (columns - 1)) {
            // If all of the inputs passed as high,
            // we can safely know no button is being pressed
            no_button_pressed = 1;
        }
    }
    // If no button is pressed, we write all the output pins to low
    if (no_button_pressed == 1) {
        for (byte i = 0; i < rows; i++) {
            digitalWrite(Output[i], LOW);
        } 
        // Loop through all of the collumns and check:
        // If the input of a specific column is low,
        // one (or more) keys in that column is being pressed,
        // we will return the first one pressed
        for (byte c = 0; c < columns; c++) {
            if (digitalRead(Input[c]) == LOW) {
                // Loop through all of the rows, and set their
                // pins to high, if the voltage of the current column
                // is then also high, we know which specific row was pressed
                for (byte r = 0; r < rows; r++) {
                    digitalWrite(Output[r], HIGH);
                    if (digitalRead(Input[c]) == HIGH) {
                        // Reset the voltages of all the pins
                        for (byte i = 0; i < rows; i++) {
                            digitalWrite(Output[i], LOW);
                        }
                        // Return number of button, we can get this by
                        // taking the row we're on and multiplying it by 4 (rows are labeled 0-3)
                        // and then adding the number of the button in the current column (also labeled 0-3)
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
    // Poll the key every 1 millisecond
    delay(10);
    // Get the current key input as a number from
    // getKeypadInput and convert to a hex code using
    // the helper function toHex above
    const char pressed = toHex(getKeypadInput());
    // If the key pressed is the same as the
    // last key press, we end the loop early
  	if (pressed == last) {
   	    return; 
  	}
    // Key pressed converted to hex will be '?' if a valid
    // number from 0 to 15 (keypad code) was not returned
    if (pressed != '?') {
        Serial.println(pressed);
    }
    // Set the currently pressed key, or '?' if none,
    // as the last pressed key to check for in the
    // next iteration of this loop
    last = pressed;
}