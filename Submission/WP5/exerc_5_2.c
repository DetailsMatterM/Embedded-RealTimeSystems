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
    busy = true;
    for (byte i = 0; i < rows; i++) {
      digitalWrite(Output[i], LOW);
    }
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
    for (byte i = 0; i < rows; i++) {
      digitalWrite(Output[i], LOW);
    }
    busy = false;
  }
}

void checkTemp() {
  int valRaw = analogRead(analogPin);
  temperature = (0.4902 * valRaw) -50;
  Serial.println(temperature);
}

void loop() {
  if (!busy) {
    if (pressed) {
      Serial.println(pressedKey, HEX);
      pressedKey = 0;
      pressed = false;
    }
  }
  
  if (millis() == time + 500) {
  	checkTemp();
    time = millis();
  }
}