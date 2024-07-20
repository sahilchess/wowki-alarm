#include <Wire.h>
#include <LiquidCrystal.h>
#include "RTClib.h"

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tues", "Wed", "Thur", "Fri", "Sat"};


LiquidCrystal lcd(12, 11, 10, 9, 8, 7);


void setup()
{
  Wire.begin();
  // Initializes the LCD
  lcd.begin(0, 0);

 
}

void loop()
{
    DateTime now = rtc.now();
      lcd.print("Current time: ");
      lcd.setCursor(0, 1);
      //lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
      lcd.print("");
      lcd.print(now.hour(), DEC);
      lcd.print(':');
      lcd.print(now.minute(), DEC);
      lcd.print(':');
      lcd.print(now.second(), DEC);
      lcd.println();
      lcd.clearScreen();
  delay(1000);
}

