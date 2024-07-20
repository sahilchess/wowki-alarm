#include <Wire.h>
#include <LiquidCrystal.h>
#include "RTClib.h"
#include "pitches.h"

#define LDR_PIN A0
#define SPEAKER_PIN 6


// These constants should match the photoresistor's "gamma" and "rl10" attributes
const float GAMMA = 0.7;
const float RL10 = 50;





RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tues", "Wed", "Thur", "Fri", "Sat"};


LiquidCrystal lcd(12, 11, 10, 9, 8, 7);


void setup()
{
  Serial.begin(115200);
//kill function
  if (! rtc.begin()) {
    
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

//pin mdoes
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);

  Wire.begin();
  // Initializes the LCD
  lcd.begin(1, 1);

 
}

void loop()
{
  int analogValue = analogRead(A0);
  float voltage = analogValue / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));  
    
    
    
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
  if (lux >= 400) {
    digitalWrite(LED_BUILTIN, HIGH);
    tone(SPEAKER_PIN, NOTE_G4);
    delay(250);
    tone(SPEAKER_PIN, NOTE_C5);
    delay(250);
    tone(SPEAKER_PIN, NOTE_G4);
    delay(250);
    tone(SPEAKER_PIN, NOTE_C5);
    delay(250);
    tone(SPEAKER_PIN, NOTE_C4);
    delay(1000);
    noTone(SPEAKER_PIN);
    digitalWrite(LED_BUILTIN, LOW);
  } else {
      return;
    }
  
}


