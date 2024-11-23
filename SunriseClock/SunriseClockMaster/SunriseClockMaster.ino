//Sunrise clock. Yeah boy!

//RTC module libraries
#include <Wire.h>
#include <SparkFunDS1307RTC.h>

//FastLED libraries to control the LED boards
#include <FastLED.h>

//Library for 4-7 Segment display serial
#include <SoftwareSerial.h>

//LED variables
#define NUM_LEDS 16
#define LED_DATA_PIN 11
#define LED_CLOCK_PIN 13

//Serial display variables
#define SERIAL_CLOCK_RX_PIN 7
#define SERIAL_CLOCK_TX_PIN 8

//Create the LED array
CRGB leds[NUM_LEDS];

//Create serial 7 segment display
SoftwareSerial serial7Segment(SERIAL_CLOCK_RX_PIN,SERIAL_CLOCK_TX_PIN);

//Initialize variables for time display

//Used for sprintf (printing long strings to serial)
char timeString[100];

void setup() {
  //Setup FastLED for SparkFun Lumenati modules (APA201C)
  FastLED.addLeds<APA102, LED_DATA_PIN, LED_CLOCK_PIN, BGR>(leds, NUM_LEDS);

  //Set global starting LED brightness
  FastLED.setBrightness(5);      

  // Use the serial monitor to view time/date output
  Serial.begin(9600);

  // Initialize the real-time clock module library and set the time manually
  rtc.begin();
  //rtc.autoTime();
  //rtc.setTime(00, 27, 21, 1, 03, 11, 24); // SEC:MIN:HH Day(1(Sunday)-7), DD, MM, YY
  // rtc.set24Hour();

  //Start talking with S7S display, clear display, set brightness to 75%, turn on colon
  serial7Segment.begin(9600);
  serial7Segment.write('v');
  serial7Segment.write(0x7A);
  serial7Segment.write((byte) 100);
  serial7Segment.write(0x77);
  serial7Segment.write((byte) 16);
}

void loop() {
  
  rtc.update();
  // printTime();  //Useful for debugging, turned off for normal operation
  updateDisplay();
  sunriseAnimation(5,30);
}
