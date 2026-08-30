#include <TimeLib.h>
#include <LiquidCrystal.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

//variable to ensure, that time in serial port change only once per minute 
int lastMin = -1;

LiquidCrystal lcd(12, 6, 5, 4, 3, 2);


void setup() {
  
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Test log");

  //AUTO TIME SYNC:
  //extract the hour, minute, and second from the computer's compilation time (__TIME__)
  int hr = cstr2int(__TIME__);
  int min = cstr2int(__TIME__ + 3);
  int sec = cstr2int(__TIME__ + 6);

  //extract day, month, year from computer's date (__DATE__)
  int d = cstr2int(__DATE__ + 4);
  int yr = cstr2int(__DATE__ + 7);
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
  addZeroIfNumNotTen(hour());
  Serial.print(":");
  addZeroIfNumNotTen(minute());
  Serial.print(" | ");

  //date displaying in serial monitor 
  addZeroIfNumNotTen(day());
  Serial.print(".");
  addZeroIfNumNotTen(month());
  Serial.print(".");
  addZeroIfNumNotTen(year());
  Serial.println("");

  //time displaying on LCD

  //date displaying on LCD

}

//func that adds 0 before numbers if those are lower than 10
void addZeroIfNumNotTen(int num) {

  if (num < 10) Serial.print('0');
  Serial.print(num);

}

// NOWA FUNKCJA POMOCNICZA:
// Przetwarza wewnętrzny tekst kompilatora (np. "17") na prawdziwą liczbę int (17)
int cstr2int(const char *str) {
  int numer = 0;
  while (*str >= '0' && *str <= '9') {
    numer = numer * 10 + (*str - '0');
    str++;
  }
  return numer;
}
