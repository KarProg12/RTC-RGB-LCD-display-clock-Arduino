#include <TimeLib.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

void setup() {
  
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  //set start date and hour (format: hour, minute, second, day, month, year)
  setTime(16, 15, 0, 30, 8, 2026);

}

void loop() {

  setColor(255, 0, 0);
  displayTime();
  delay(1000);

}

void setColor(int red, int green, int blue) {

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

}

void displayTime() {
  //display time 
  addZeroIfNumNotTen(hour());
  Serial.print(":");
  addZeroIfNumNotTen(minute());
  Serial.print(":");
  addZeroIfNumNotTen(second());
  Serial.print(" ");

  //display date
  addZeroIfNumNotTen(day());
  Serial.print(".");
  addZeroIfNumNotTen(month());
  Serial.print(".");
  addZeroIfNumNotTen(year());
  Serial.println("");

}

//function which adds 0 if number is below 10
void addZeroIfNumNotTen(int num) {
  if (num < 10) {
    Serial.print('0');
  }
  Serial.print(num);
}
