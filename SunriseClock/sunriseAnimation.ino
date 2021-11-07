void sunriseAnimation(){

 static int8_t checkVar = 0;
  
  if(rtc.hour() == 6 && rtc.minute() == 0 && checkVar == 0){
      FastLED.setBrightness(8);      
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i].red = 130;
        leds[i].blue = 199;
        leds[i].green = 218;
        FastLED.show();
      }   
    checkVar = 1;
  }
  if(rtc.hour() == 6 && rtc.minute() == 8 && checkVar == 1){
    FastLED.setBrightness(14);
    FastLED.show();
    checkVar = 2;
  }
  if(rtc.hour() == 6 && rtc.minute() == 16 && checkVar == 2){
    FastLED.setBrightness(20);
    FastLED.show();
    checkVar = 3;
  }
  if(rtc.hour() == 6 && rtc.minute() == 24 && checkVar == 3){
    FastLED.setBrightness(32);
    FastLED.show();
    checkVar = 4;
  }
  if(rtc.hour() == 6 && rtc.minute() == 35 && checkVar == 4){
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i].red = 0;
      leds[i].blue = 0;
      leds[i].green = 0;
      FastLED.show();
    }
    checkVar = 0;
  }
}
