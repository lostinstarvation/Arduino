void setLEDBrightness(int brightness){
  FastLED.setBrightness(brightness);
  FastLED.show();
}

void setLEDColor(int red, int green, int blue){
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].red = red;
    leds[i].green = green;
    leds[i].blue = blue;
    FastLED.show();
  }   
}

void sunriseAnimation(int startHour, int startMinute){
  static int lastMinuteSunrise = -1;

  int currentHour = rtc.hour();
  int currentMinute = rtc.minute();

  if (currentMinute != lastMinuteSunrise){ //Only evaluate once per minute
    int elapsedMinutes = (currentHour * 60 + currentMinute) - (startHour * 60 + startMinute);

    if (elapsedMinutes >=0 && elapsedMinutes <=60){
      int brightness = map(elapsedMinutes, 0, 60, 5, 40); //adjust brightness between 5 and 40 based on length of elapsed minutes
      setLEDBrightness(brightness);
      
      if (elapsedMinutes == 0){
        setLEDColor(130,218,199);
      }
      else if (elapsedMinutes == 60){
        setLEDColor(0,0,0);
      }
      lastMinuteSunrise = currentMinute;
    }
  }
}
