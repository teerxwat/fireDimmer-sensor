#include <BH1750FVI.h>                                 //ประกาศ header file 
#include "Timer.h"                                     //ประกาศ header file 
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes); // สร้างออปเจกเซนเซอร์ BH1750
Timer delayT;                                          //ประกาศตัวแปร ของ Timer ชื่อ delayT
#define showLED D6                                     //ประกาศตัวแปร ชื่อ showLED ให้เป็นขาที่ 6 
#define sensorMovement D0                              //ประกาศตัวแปร ชื่อ sensorMovement ให้เป็นขาที่ 0 
int cost_LED = 1023 ;                                  //ประกาศตัวแปรชื่อว่า cost_LED กำหนดให้มีค่าเป็น 1023
int y = 0;                                             //ประกาศตัวแปรชื่อว่า y กำหนดให้มีค่าเป็น 0
int temp = 0;                                          //ประกาศตัวแปรชื่อว่า temp กำหนดให้มีค่าเป็น 0 

void setup() {
  pinMode(D3, OUTPUT);
  pinMode(showLED, OUTPUT);                   //กำหนดขา showLED เป็นขาออก
  pinMode(sensorMovement, INPUT);             //กำหนดขา sensorMovement ให้เป็นขาเข้า
  Serial.begin(9600);                         //กำหนดบอร์ดเรท
  LightSensor.begin();                        //การทำงานของเซ็นเซอร์
}

void loop() {
  chkSensor();  //เรียกใช้ฟังก์ชั่น
}

void chkSensor() { //สร้างฟังก์ชั่นชื่อ chkSensor 
  int value = digitalRead(sensorMovement);  //สร้างตัวแปรเพื่อนเก็บค่าของเซ็นเซอร์
  uint16_t lux = LightSensor.GetLightIntensity();  //สร้างตัวแปรเพื่อนเก็บค่าของเซ็นเซอร์
  y = map(lux, 1, 54612, 1, 1023); //map ขนาดของค่าที่ได้ออกมา ให้เริ่มต้นที่ 1 ไปถึง 1023
  Serial.println(value);  //แสดงค่าการเคลื่อนไหว
  if (value == HIGH) //ถ้าเซ็นเซอร์มีค่าเท่ากับ 1 ?
  { //เริ่มการทำงานif
    Serial.println(" พบสิ่งเคลื่อนไหว "); //แสดงข้อความ
    showLEDDt(); //เรียกใช้ฟังก์ชั่น การแสดงค่า LED 
  } //จบการทำงาน if
  if (value == LOW) //ถ้าเซ็นเซอร์เท่ากับ 0 ?
  { //เริ่มการทำงานif
    Serial.println(" ไม่พบสิ่งเคลื่อนไหว ");  //แสดงข้อความ
    digitalWrite(showLED, LOW); //กำหนดให้ led ดับ
  } //จบการทำงานif
} //จบฟังก์ชั่น

void showLEDDt(){ //สร้างฟังก์ชั่น showLED
  if( y > 900 && y <= 1023 ){ 
    temp = 123 ;  //กดหนดค่าความสว่างของหลอดไฟ
    analogWrite(showLED, temp); //โชว์ค่าความสว่างของไฟ ตามค่า temp
  }else if( y > 800 && y <= 899 ){
    temp = 200 ;  //กดหนดค่าความสว่างของหลอดไฟ
    analogWrite(showLED, temp); //โชว์ค่าความสว่างของไฟ ตามค่า temp
  }else if( y >= 700 && y <= 799 ){
    temp = 300 ;  //กดหนดค่าความสว่างของหลอดไฟ
    analogWrite(showLED, temp); //โชว์ค่าความสว่างของไฟ ตามค่า temp
  }else if( y >= 600 && y <= 699 ){
    temp = 400 ;  //กดหนดค่าความสว่างของหลอดไฟ
    analogWrite(showLED, temp); //โชว์ค่าความสว่างของไฟ ตามค่า temp
  }else if( y >= 500 && y <= 599 ){
    temp = 500 ;  //กดหนดค่าความสว่างของหลอดไฟ
    analogWrite(showLED, temp); //โชว์ค่าความสว่างของไฟ ตามค่า temp
  }else if( y >= 400 && y <= 499 ){
    temp = 600 ;  //กดหนดค่าความสว่างของหลอดไฟ
    analogWrite(showLED, temp); //โชว์ค่าความสว่างของไฟ ตามค่า temp 
  }else if( y >= 300 && y <= 399 ){
    temp = 700 ;  //กดหนดค่าความสว่างของหลอดไฟ
    analogWrite(showLED, temp); //โชว์ค่าความสว่างของไฟ ตามค่า temp
  }else if( y >= 200 && y <= 299 ){
    temp = 800 ;  //กดหนดค่าความสว่างของหลอดไฟ
    analogWrite(showLED, temp); //โชว์ค่าความสว่างของไฟ ตามค่า temp 
  }else if( y >= 100 && y <= 199 ){
    temp = 900 ;  //กดหนดค่าความสว่างของหลอดไฟ
    analogWrite(showLED, temp); //โชว์ค่าความสว่างของไฟ ตามค่า temp
  }else if( y >= 0 && y <= 99 ){  
    temp = 1000 ; //กดหนดค่าความสว่างของหลอดไฟ
    analogWrite(showLED, temp); //โชว์ค่าความสว่างของไฟ ตามค่า temp
  } //จบคำสั่ง if 
}//จบการทำงานฟังก์ชั่น
