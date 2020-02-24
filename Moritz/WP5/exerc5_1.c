const byte rows = 4;
const byte columns = 4;
const byte Output[rows] = {11, 10, 9, 8}; 
const byte Input[columns] = {7, 6, 5, 4};

volatile bool pressed = false;
volatile byte pressedKey;

void setup() {
  Serial.begin(9600);
  for (byte i = 0; i < rows; i++) {
    pinMode(Output[i], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(2), press, FALLING);
}

volatile bool busy = false;
void press() {
  if (!busy) {
    // Mark as busy (debounce) to prevent this code from running more than once at the same time
    busy = true;
    // Reset all the voltages
    for (byte i = 0; i < rows; i++) {
      digitalWrite(Output[i], LOW);
    }
    // Check for any key press and break if a key was pressed
    for (byte c = 0; c < columns; c++) {
      if (pressed) {
        break;
      }
      if (digitalRead(Input[c]) == LOW) {
        for (byte r = 0; r < rows; r++) {
          digitalWrite(Output[r], HIGH);
          if (digitalRead(Input[c]) == HIGH) {
            pressedKey = r * 4 + c;
            pressed = true;
            break;
          }
        }
      }
    }
    // Reset all the voltages again
    for (byte i = 0; i < rows; i++) {
      digitalWrite(Output[i], LOW);
    }
    // Mark as not busy so we can check voltages again
    busy = false;
  }
}

void loop() {
  // Wait for any interrupt to finish processing
  if (!busy) {
    // Check if we pressed anything
    if (pressed) {
      // Print whatever we pressed
      Serial.println(pressedKey, HEX);
      // Reset back to defaults
      pressedKey = 0;
      pressed = false;
    }
  }
}