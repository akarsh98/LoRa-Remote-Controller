//+RCV=0,2,UP,-66,49

// TAKES IN DATA FROM SERIAL MONITOR AND SENDS IT THROUGH LORA IN BROADCAST MANNER.

#include <SoftwareSerial.h>                           //we have to include the SoftwareSerial library, or else we can't use it
#define rx 13                                          //LORA TX
#define tx 15                                          //LORA RX
String incomingString;
String PrStr;                                           // String used to print the incoming string after decoding it
int led4 = 0;
int led5 = 0;
SoftwareSerial myserial(rx, tx);                      //define how the soft serial port is going to work


void setup() {
  Serial.begin(115200);
  myserial.begin(115200);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
}

void loop() {
  
  if (myserial.available()){                  // this will read the incomming data from the lora and decode it and print it on serial monitor
        incomingString = myserial.readString();
        String recTest = incomingString.substring(1,4);
        if(recTest == "RCV"){
        String messagesize;
        int addr_start = incomingString.indexOf(',');
        int addr_mid = incomingString.indexOf(',', addr_start + 1);
        messagesize = incomingString.substring(addr_start + 1, addr_mid);
        PrStr = incomingString.substring(addr_mid + 1, (addr_mid + 1 + messagesize.toInt()));
        if(PrStr=="UP"){
            if(led4==1){
              digitalWrite(4, LOW);
              led4=0;
            }
            else {
              digitalWrite(4, HIGH);
              led4=1;
            }
        }
        if(PrStr=="BACK"){
            if(led5==1){
              digitalWrite(5, LOW);
              led5=0;
            }
            else {
              digitalWrite(5, HIGH);
              led5=1;
            }
        }
        }
    }

}
