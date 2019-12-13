#include <SoftwareSerial.h>

#define RLY1  4  

SoftwareSerial loraSerial(10,11); // TX, RX

unsigned long temp;
int duration = 2000;

void setup() {
  pinMode(RLY1, OUTPUT);
  Serial.begin(9600);
  loraSerial.begin(9600); 
  temp = millis(); 
}


void loop() { 
  if(loraSerial.available() > 1){
    String input = loraSerial.readString();
    Serial.println(input);  
    if(input == "1ON") {
      digitalWrite(RLY1, HIGH); 
      temp = millis(); 
    } 
   
  }
  delay(20);

  if((temp+duration)<millis()){
    digitalWrite(RLY1, LOW); 
  }
}
