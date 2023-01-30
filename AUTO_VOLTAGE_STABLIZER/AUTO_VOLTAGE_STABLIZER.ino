int RS = 13;
int EN = 12;
int D4 = 11;
int D5 = 10;
int D6 = 9;
int D7 = 8;
#include <LiquidCrystal.h>
LiquidCrystal lcd (RS, EN, D4, D5, D6, D7);
int supply = A2; //grid volt_pin
int volt_pin = A4; //stablized output volt_pin
int tap1 = 3; //160v
int tap2 = 4; //190v
int tap3 = 5; //220
int tap4 = 6; //250
int tap5 = 7; //280
float volt_read;
float AC_volt;
float Reg_volt;
float calibrator = sqrt(2);
float r1 = 1000000; //1mega resistor
float r2 = 4400; //4.4k resistor...
float r3 = 1000000; //1mega resistor
float r4 = 4400; //4.4k resistor...
float AC_rectified;
float Stablized;
int Alarm = 2;

void setup() {
  // put your setup code here, to run once:
pinMode(RS,OUTPUT);
pinMode(EN,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(D5,OUTPUT);
pinMode(D6,OUTPUT);
pinMode(D7,OUTPUT);
pinMode(tap1,OUTPUT);
pinMode(tap2,OUTPUT);
pinMode(tap3,OUTPUT);
pinMode(tap4,OUTPUT);
pinMode(tap5,OUTPUT);
pinMode(Alarm,OUTPUT);
pinMode(supply,INPUT);
pinMode(volt_pin,INPUT);
lcd.begin(16,2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" INITIALIZING...");
delay(1000);
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
volt_read = analogRead(supply);
float analog_to_volt = volt_read * 0.004887585533;
AC_rectified = ((r1 + r2)*analog_to_volt)/r2;
AC_volt = round(AC_rectified);
//here is for the stablized output voltage...
float volt_read2 = analogRead(volt_pin);
float analog_to_volt2 = volt_read2 * 0.004887585533;
Stablized = ((r3 + r4)*analog_to_volt2)/r4;
Reg_volt = round(Stablized*1.00456621);
lcd.setCursor(0,0);
lcd.print("INPUT VOLT ");
lcd.print(AC_volt);
lcd.print("V");
lcd.setCursor(0,1);
lcd.print("OUTPUT VOLT ");
lcd.print(Reg_volt);
lcd.print("V");

if(AC_volt >= 100 && AC_volt <= 180){
  digitalWrite(tap5, LOW);
  digitalWrite(tap4, LOW);
  digitalWrite(tap3, HIGH);
  digitalWrite(tap2, LOW);
  digitalWrite(tap1, LOW);
  lcd.setCursor(0,0);
lcd.print("INPUT VOLT ");
lcd.print(AC_volt);
lcd.setCursor(0,1);
lcd.print("OUTPUT VOLT ");
lcd.print(Reg_volt);
}else if(AC_volt >= 181 && AC_volt <= 210){
  digitalWrite(tap5, LOW);
  digitalWrite(tap4, LOW);
  digitalWrite(tap3, HIGH);
  digitalWrite(tap2, LOW);
  digitalWrite(tap1, LOW);
  lcd.setCursor(0,0);
lcd.print("INPUT VOLT ");
lcd.print(AC_volt);
lcd.setCursor(0,1);
lcd.print("OUTPUT VOLT ");
lcd.print(Reg_volt);
}else if(AC_volt >= 210 && AC_volt <= 240){
  digitalWrite(tap5, LOW);
  digitalWrite(tap4, LOW);
  digitalWrite(tap3, HIGH);
  digitalWrite(tap2, LOW);
  digitalWrite(tap1, LOW);
  lcd.setCursor(0,0);
lcd.print("INPUT VOLT ");
lcd.print(AC_volt);
lcd.setCursor(0,1);
lcd.print("OUTPUT VOLT ");
lcd.print(Reg_volt);
}else if(AC_volt >= 241 && AC_volt <= 270){
  digitalWrite(tap5, LOW);
  digitalWrite(tap4, LOW);
  digitalWrite(tap3, LOW);
  digitalWrite(tap2, HIGH);
  digitalWrite(tap1, LOW);
  lcd.setCursor(0,0);
lcd.print("INPUT VOLT ");
lcd.print(AC_volt);
lcd.setCursor(0,1);
lcd.print("OUTPUT VOLT ");
lcd.print(Reg_volt);
}else if(AC_volt >= 271 && AC_volt <= 280){
  digitalWrite(tap5, LOW);
  digitalWrite(tap4, LOW);
  digitalWrite(tap3, LOW);
  digitalWrite(tap2, LOW);
  digitalWrite(tap1, HIGH);
  lcd.setCursor(0,0);
lcd.print("INPUT VOLT ");
lcd.print(AC_volt);
lcd.setCursor(0,1);
lcd.print("OUTPUT VOLT ");
lcd.print(Reg_volt);
}else{
  digitalWrite(tap5, LOW);
  digitalWrite(tap4, LOW);
  digitalWrite(tap3, LOW);
  digitalWrite(tap2, LOW);
  digitalWrite(tap1, LOW);
  digitalWrite(Alarm,HIGH);
  delay(50);
  digitalWrite(Alarm,LOW);
  delay(50);
}
}
