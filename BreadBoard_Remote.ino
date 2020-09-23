#include <SoftwareSerial.h>    
#define rx 5                                          //LORA TX
#define tx 4                                          //LORA RX

const int buttonPin = 13;    // the number of the pushbutton pin

// Variables will change:
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
SoftwareSerial myserial(rx, tx);     

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(115200);
  myserial.begin(115200);
  Serial.println("Button");
}

void loop() {

  bool reading = digitalRead(buttonPin);
 
    if (reading == HIGH && lastButtonState != HIGH) {
      buttonState = reading;
      Serial.println("Button");
      myserial.println("AT+SEND=0,2,UP");
    }
  lastButtonState = reading;
  delay(20);
}
