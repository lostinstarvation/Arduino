void updateDisplay() {
  static int8_t lastHour = -1;
  static int8_t lastMinute = -1;
  
  static int8_t displayHour = 0;
  static int8_t displayMinute = 0; 
   
  if (rtc.hour() != lastHour){
    if(rtc.hour() >= 13){
      displayHour = rtc.hour() - 12;
    }
    else{
      displayHour = rtc.hour();  
    }
    lastHour = rtc.hour();
  }
  if (rtc.minute() != lastMinute){
    displayMinute = rtc.minute();
    /* Used for testing. Turned off for normal operation
    sprintf(timeString, "HH:MM %02d:%02d", displayHour, displayMinute);
    Serial.println(timeString);
    */
    sprintf(timeString, "%02d%02d", displayHour, displayMinute);
    serial7Segment.print(timeString);
    
    lastMinute = rtc.minute();  
  }    
}
