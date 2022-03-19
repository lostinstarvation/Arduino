void updateDisplay() {
  static int8_t lastHour = -1;
  static int8_t lastMinute = -1;
  
  static int8_t displayHour = 0;
  static int8_t displayMinute = 0; 
   
  if (rtc.hour() != lastHour){
    if(rtc.hour() >= 13){
      switch(rtc.hour()){
        case 13:
          displayHour = 1;
          lastHour = rtc.hour();
          break;
        case 14:
          displayHour = 2;
          lastHour = rtc.hour();
          break;
        case 15:
          displayHour = 3;
          lastHour = rtc.hour();
          break;
        case 16:
          displayHour = 4;
          lastHour = rtc.hour();
          break;
        case 17:
          displayHour = 5;
          lastHour = rtc.hour();
          break;
        case 18:
          displayHour = 6;
          lastHour = rtc.hour();
          break;
        case 19:
          displayHour = 7;
          lastHour = rtc.hour();
          break;
        case 20:
          displayHour = 8;
          lastHour = rtc.hour();
          break;
        case 21:
          displayHour = 9;
          lastHour = rtc.hour();
          break;
        case 22:
          displayHour = 10;
          lastHour = rtc.hour();
          break;
        case 23:
          displayHour = 11;
          lastHour = rtc.hour();
          break;
        case 24:
          displayHour = 12;
          lastHour = rtc.hour();
          break;
      }
    }
    else{
      displayHour = rtc.hour();
      lastHour = rtc.hour();    
    }
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
