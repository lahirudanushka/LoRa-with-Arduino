#include <SoftwareSerial.h>

#define BTN1  4
 

SoftwareSerial loraSerial(10,11); // TX, RX


void setup() {
  pinMode(BTN1, INPUT_PULLUP);
  
  Serial.begin(9600);
  loraSerial.begin(9600);
  
}

void loop() {

  if(digitalRead(BTN1) == 0) {
    loraSerial.print("1ON");
    while(digitalRead(BTN1) == 0);
    delay(50);
  }


}
