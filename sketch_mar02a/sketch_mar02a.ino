#include <SoftwareSerial.h>

SoftwareSerial char(D5); // RX, TX
char a;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  chat.begin(4800);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(a);
}
