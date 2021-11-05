void sunriseAnimation(){

 static int8_t checkVar = 0;
  
  if(rtc.hour() == 6 && rtc.minute() == 0 && checkVar == 0){
      FastLED.setBrightness(5);      
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i].red = 173;
        leds[i].blue = 255;
        leds[i].green = 218;
        FastLED.show();
      }   
    checkVar = 1;
  }
  if(rtc.hour() == 6 && rtc.minute() == 8 && checkVar == 1){
    FastLED.setBrightness(10);
    FastLED.show();
    checkVar = 2;
  }
  if(rtc.hour() == 8 && rtc.minute() == 16 && checkVar == 2){
    FastLED.setBrightness(15);
    FastLED.show();
    checkVar = 3;
  }
  if(rtc.hour() == 8 && rtc.minute() == 24 && checkVar == 3){
    FastLED.setBrightness(30);
    FastLED.show();
    checkVar = 4;
  }
  if(rtc.hour() == 8 && rtc.minute() == 35 && checkVar == 4){
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i].red = 0;
      leds[i].blue = 0;
      leds[i].green = 0;
      FastLED.show();
    }
    checkVar = 0;
  }
}
