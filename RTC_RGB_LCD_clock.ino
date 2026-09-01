#include <RtcDS1302.h>
#include <ThreeWire.h>
#include <LiquidCrystal.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

//LCD
LiquidCrystal lcd(12, 6, 5, 4, 3, 2);
//Rtc
ThreeWire myWire(13, 8, 7); //DAT, CLK, RST
RtcDS1302<ThreeWire> Rtc(myWire); //Rtc object
int lastMin = -1;
int compilationTime = 6; 


void setup() {
  
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  //LCD
  lcd.begin(16, 2);
  //Rtc
  Rtc.Begin();

  //'unlock' DS1302 memory lock to be able to update time in clock's memory
  if (Rtc.GetIsWriteProtected())  Rtc.SetIsWriteProtected(false); 

  //check if RTC's inner oscilator isn't running and if it's true (if it is NOT running)
  //set it to running/true/ON so it'll be still measuring time even though it has no power
  //RTC requires pill-shaped battery for inner oscilator to work  
  if (!Rtc.GetIsRunning())  Rtc.SetIsRunning(true);   

  //TIME SETTING: 
  //pull date and time from pc's clock
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

  //checks if time & date is NOT valid and then synces the time & date 
  //and adds 6 seconds to eliminate latency caused by compilation & uploading time  
  if (!Rtc.IsDateTimeValid()) {
    RtcDateTime eliminatedCompilationTime = compiled + compilationTime;
    Rtc.SetDateTime(eliminatedCompilationTime);
  }

}

void loop() {

  displayTime();
  colorForTimeOfDay();

}
//RGB color setting red, green, blue
void setColor(int red, int green, int blue) {

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

}

//set RGB color for each time of the day
void colorForTimeOfDay() {
  
  RtcDateTime now = Rtc.GetDateTime();
  int hour = now.Hour();

  //morning color 0, 85, 255
  if (hour >= 6 && hour < 9) {
    setColor(0, 85, 255);
  }

  //late morning color 255, 85, 0
  else if (hour >= 9 && hour < 12) {
    setColor(255, 85, 0);
  }

  //noon color 0, 0, 255
  else if (hour >= 12 && hour < 15) {
    setColor(0, 0, 255);
  }

  //afternoon color 0, 153, 255
  else if (hour >= 15 && hour < 18) {
    setColor(0, 153, 255);
  }

  //evening color 0, 204, 255
  else if (hour >= 18 && hour < 22) {
    setColor(0, 204, 255);
  }

  //night color 204, 255, 85
  else {
    setColor(204, 255, 85);
  }

}

void displayTime() {
  //time displaying in serial monitor
  RtcDateTime now = Rtc.GetDateTime();

  if (now.Minute() != lastMin) {
    lastMin = now.Minute(); //save current minute as last minute
    
    lcd.clear();

  //display time on LCD
  lcd.setCursor(5, 0);
  lcdAddZero(now.Hour());
  lcd.print(":");
  lcdAddZero(now.Minute());
 
  //display date on LCD
  lcd.setCursor(3, 1);
  lcdAddZero(now.Day());
  lcd.print(".");
  lcdAddZero(now.Month());
  lcd.print(".");
  lcd.print(now.Year());
  }

}

//function that makes it easier to set time on rtc 'cause it has time & date in better order than Makuna's Rtc.setDateTime()  
void rtcSetTime(int hour, int minute, int second, int day, int month, int year) {
  
  RtcDateTime dateAndTime(year, month, day, hour, minute, second);
  Rtc.SetDateTime(dateAndTime);

}

//fuction that adds zero tu numbers below 10 (don't use it in year displaying 'cause it makes no sense (for now at least XD))
void lcdAddZero(int num) {
  
  if (num < 10) {
    lcd.print('0');
  }
  lcd.print(num);

}