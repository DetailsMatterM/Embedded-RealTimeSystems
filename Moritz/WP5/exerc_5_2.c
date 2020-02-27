/* ====================================
File name: exerc_5_2.c 
Date: 2019-02-27
Group Number:07
Members that contributed:
Fredrik Ullman
Mikael Köse Jansson
Moritz Denke
Demonstration code: [22589] Important !
====================================== */
const byte rows = 4;
const byte columns = 4;
const byte Output[rows] = {11, 10, 9, 8}; 
const byte Input[columns] = {7, 6, 5, 4};
int analogPin = A0;
volatile bool pressed = false;
volatile byte pressedKey;
unsigned long time;
double temperature;
void setup() {
  Serial.begin(9600);
  for (byte i = 0; i < rows; i++) {
    pinMode(Output[i], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(2),press,FALLING);
  time = millis();
}

volatile bool busy = false;
void press(){
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

void checkTemp() {
  int valRaw = analogRead(analogPin);
  temperature = (double)valRaw / 1024;  
  temperature = temperature * 5;  //gets the voltage                   
  temperature = temperature - 0.5;   //remove the offset                
  temperature = temperature * 100;  //calculate degree
  Serial.println(temperature);
}

void loop() {
   // Wait for any interrupt to finish processing
  if (!busy) {
    // Check if we pressed anything
    if (pressed) {
      Serial.println(pressedKey, HEX);
      // Reset back to defaults
      pressedKey = 0;
      pressed = false;
    }
  }
  
  if (millis() == time + 500) {
  	checkTemp();
    time = millis();
  }
}