const byte rows = 4;
const byte columns = 4;
const byte Output[rows] = {11, 10, 9, 8}; 
const byte Input[columns] = {7, 6, 5, 4};

bool pressed = false;
byte pressedKey;

void setup() {
    Serial.begin(9600);
    for (byte i = 0; i < rows; i++) {
        pinMode(Output[i], OUTPUT);
    }
  	attachInterrupt(digitalPinToInterrupt(2),press,FALLING);
}

void press(){
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
                        
                        pressedKey = r * 4 + c;
                        pressed = true;
                        return;
                    }
                }
            }
        }
}

void loop() {
  if (pressed) {
    pressed = false;
    Serial.println(pressedKey, HEX);
  }
    
}