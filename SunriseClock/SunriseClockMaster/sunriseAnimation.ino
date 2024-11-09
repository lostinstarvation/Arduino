#include <cstdint>

void setLEDBrightness(int8_t brightness){
  FastLED.setBrightness(brightness);
  FastLED.show();
}

void setLEDColor(int8_t red, int8_t green, int8_t blue){
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].red = red;
    leds[i].green = green;
    leds[i].blue = blue;
    FastLED.show();
  }   
}

void sunriseAnimation(int8_t startHour, int8_t startMinute){
  static int8_t checkVar = 0;
  int8_t elapsedMinutes = (rtc.hour() * 60 + rtc.minute()) - (startHour * 60 + rtc.minute());

  if(elapsedMinutes >=0 && elapsedMinutes <=60){
    int8_t brightness = map(elapsedMinutes, 0, 60, 5, 40); //adjust brightness between 5 and 40 based on length of elapsed minutes
    if(elapsedMinutes == 0){
      setLEDColor(130,218,199);
    }
    else if(elapsedMinutes == 60){
      setLEDColor(0,0,0);
    }
    setLEDBrightness(brightness);
  }
}
