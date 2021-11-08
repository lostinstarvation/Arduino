void printTime(){
  static int8_t lastSecond = -1;
  
  if (rtc.second() != lastSecond){
    Serial.print(String(rtc.hour()) + ":"); // Print hour
    if (rtc.minute() < 10)
      Serial.print('0'); // Print leading '0' for minute
    Serial.print(String(rtc.minute()) + ":"); // Print minute
    if (rtc.second() < 10)
      Serial.print('0'); // Print leading '0' for second
    Serial.print(String(rtc.second())); // Print second
  
    Serial.print(" | ");
  
    // Few options for printing the day, pick one:
    Serial.print(rtc.dayStr()); // Print day string
    //Serial.print(rtc.dayC()); // Print day character
    //Serial.print(rtc.day()); // Print day integer (1-7, Sun-Sat)
    Serial.print(" - ");
  
    Serial.print(String(rtc.month()) + "/" +   // Print month
                   String(rtc.date()) + "/");  // Print date
  
    Serial.println(String(rtc.year()));        // Print year

    lastSecond = rtc.second();
  }
}
