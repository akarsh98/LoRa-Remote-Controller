  
#include <SoftwareSerial.h>                           //we have to include the SoftwareSerial library, or else we can't use it
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

#define rx 5                                          //LORA TX
#define tx 4                                          //LORA RX
#define TFT_CS     15
#define TFT_RST    16 
#define TFT_DC     2

int buttonstat = 0;
int prevbutton = 0;
boolean buttonact = 0;                                  // 0: pressed     1: not pressed
boolean buttonactdel = 0;

String incomingString = "gg";
String PrStr;                                           // String used to print the incoming string after decoding it

SoftwareSerial myserial(rx, tx);                      //define how the soft serial port is going to work
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  myserial.begin(115200);
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(tft.getRotation()-1);
  tft.setCursor(5, 5);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.print("LRM");
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  tft.println("  LoRa Messenger");
  tft.println();
  delay(100);
}

void loop() {
  int sensorValue = analogRead(A0);
  //tft.println(sensorValue);
  delay(20);
  if(sensorValue < 100){
    buttonstat=0;
    }
  else if(sensorValue >= 100 && sensorValue <=240){
    buttonstat=1;
    incomingString="BACK";}
  else if(sensorValue >= 350 && sensorValue <=520){
    buttonstat=2;
    incomingString="UP";}
  else if(sensorValue >= 520 && sensorValue <=700){
    buttonstat=3;
    incomingString="DOWN";}  
  else if(sensorValue > 700){
    buttonstat=4;
    incomingString="SELECT";}

  if(buttonstat==prevbutton){buttonact=0;}
  else if(buttonstat != 0)
  {buttonact=1;
  String messStr = "AT+SEND=0,";              // messStr(AT COMMAND) is to be sent to the LoRa module to send the relavant data
  messStr += (incomingString.length());
  messStr += ",";
  messStr += incomingString;
  myserial.println(messStr);
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(1);
  tft.print(incomingString);
  tft.println(" button pressed");
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(1);
  }

  prevbutton = buttonstat;                          // assign value of button status to prevbutton used to detect button press 
}
