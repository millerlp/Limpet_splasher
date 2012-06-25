/* ReatTimeClock_reset
  Use this sketch to reset the DS1307 or DS3231 Real Time Clock. 
  It will grab the computer's current time during compilation and 
  send that value to the real time clock. 
  
  Afterwards, immediately upload a different sketch to the Arduino
  so that it doesn't try to constantly reset the clock when it 
  powers up the next time. If it does reset, the Arduino will reset 
  the clock with the old compile time stamp, which will be out of
  date.
  
  *****NOTE*****
  If you botch the first attempt at resetting the clock (maybe because
  your computer time wasn't set to local standard time), you may need
  to close the Arduino IDE and restart it in order to properly 
  recompile and upload this sketch with the current correct time. A 
  change made in the recent Arduino IDE tries to speed up recompile
  time by only recompiling when code changes, but this undermines the
  behavior of this sketch, which relies on grabbing the computer time
  when compiling and uploading. If you try to run it multiple times
  in a row, it won't recompile with an updated time, so you'll be stuck
  with the old time value. Hence the need to restart the Arduino
  IDE. 
  **************
*/

#include <Wire.h>
#include <SPI.h> // Required for RTClib to compile properly
#include <RTClib.h> // From https://github.com/MrAlvin/RTClib

RTC_DS1307 RTC;

boolean resetFlag = false; // flag for clock reset

void setup(void)
{
  delay(2000);
  Wire.begin();
  RTC.begin();  
  RTC.adjust(DateTime(__DATE__, __TIME__));


  DateTime now = RTC.now();
  Serial.begin(115200);
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);  
  delay(2000);
}

void loop(void)
{
  DateTime now = RTC.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);
  delay(2000);
  

}
  
