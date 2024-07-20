#include <Wire.h>
#include <LiquidCrystal.h>
#include "RTClib.h"

#define LDR_PIN 2


RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tues", "Wed", "Thur", "Fri", "Sat"};


LiquidCrystal lcd(12, 11, 10, 9, 8, 7);


void setup()
{
  Serial.begin(115200);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
  Wire.begin();
  // Initializes the LCD
  lcd.begin(1, 1);

 
}

void loop()
{
    DateTime now = rtc.now();
      lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
      lcd.print(" ");
      lcd.print(now.hour(), DEC);
      lcd.print(':');
      lcd.print(now.minute(), DEC);
      lcd.print(':');
      lcd.print(now.second(), DEC);
      delay(1000);
      lcd.clear();
      delay(0.000000000000000000001);
}

