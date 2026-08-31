#include <TimeLib.h>
#include <LiquidCrystal.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

//variable to ensure, that time in serial port change only once per minute 
int lastMin = -1;
//extra seconds to swich power source e.g. from computer to powerbank
int powerSourceSwichTimeout = 10;

LiquidCrystal lcd(12, 6, 5, 4, 3, 2);


void setup() {
  
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  lcd.begin(16, 2);

  //AUTO TIME SYNC:
  //extract the hour, minute, and second from the computer's compilation time (__TIME__)
  int hr = cstr2int(__TIME__);
  int min = cstr2int(__TIME__ + 3);
  //add 10 seconds to eliminate compilation time 
  int sec = cstr2int(__TIME__ + 6) + powerSourceSwichTimeout;
 
  //extract day, month, year from computer's date (__DATE__)
  int d = cstr2int(__DATE__ + 4);
  int yr = cstr2int(__DATE__ + 9);
  int mo = 1;
 
  //automatic align of the month from PC (e.g. "Aug") to (e.g. 8)
  const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  for (int i = 0; i < 12; i++) {
    if (strncmp(__DATE__, months[i], 3) == 0) {
      mo = i + 1;
      break;
    }
  }

  //set time fetched form computer's time & date obtianed in time of compilation
  setTime(hr, min, sec, d, mo, yr);

}

void loop() {
  //for common anode 255 == LOW, 0 == HIGH, for common cathode 255 == HIGH, 0 == LOW
  setColor(0, 255, 255);

  //I could do it with delay(60000) (60000ms = 1min), but delay stops the program for minute
  //so I check if minute has changed and then instantly Arduino prints time with next minute
  if (minute() != lastMin) {
    lastMin = minute(); //save current minute
    lcd.clear();
    displayTime();             
  }
}

void setColor(int red, int green, int blue) {

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

}

void displayTime() {
  //time displaying in serial monitor
  serialAddZero(hour());
  Serial.print(":");
  serialAddZero(minute());
  Serial.print(" | ");

  //date displaying in serial monitor 
  serialAddZero(day());
  Serial.print(".");
  serialAddZero(month());
  Serial.print(".");
  Serial.print(year());

  //time displaying on LCD
  lcd.setCursor(5, 0);
  lcdAddZero(hour());
  lcd.print(":");
  lcdAddZero(minute());

  //date displaying on LCD
  lcd.setCursor(3, 1);
  lcdAddZero(day());
  lcd.print(".");
  lcdAddZero(month());
  lcd.print(".");
  lcd.print(year());

}

//func that adds 0 before numbers if those are lower than 10
void serialAddZero(int num) {

  if (num < 10) { 
    Serial.print('0');
  }
  Serial.print(num);
}

void lcdAddZero(int num) {

  if (num < 10) { 
    lcd.print('0');
  }
  lcd.print(num);
}

//func that processes inner compiler text e.g. "17" to e.g. 17
int cstr2int(const char *str) {
  int number = 0;
  while (*str >= '0' && *str <= '9') {
    number = number * 10 + (*str - '0');
    str++;
  }
  return number;
}
