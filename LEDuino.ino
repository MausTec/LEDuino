/*
  Default rainbow pattern sketch for the LEDuino Smol

  This cycles through the rainbow on CH1, inverse color on CH2.
 */

// Required Libraries
#import <FastLED.h>

// Define pinout
#define CH1_R_PIN  3
#define CH1_G_PIN  5
#define CH1_B_PIN  6

#define CH2_R_PIN  9
#define CH2_G_PIN 10
#define CH2_B_PIN 11

// Rainbow cycle time
#define SPEED_HZ 30
#define BRIGHTNESS 128
#define SATURATION 255
#define HUE_STEP 1

// Store two channels of color data
CRGB CH1 = CRGB::Black;
CRGB CH2 = CRGB::Black;

byte hue = 0;

void showColors();

void setup() {
  Serial.begin(115200);

  // Initialize Channel 1 pins
  pinMode(CH1_R_PIN, OUTPUT);
  pinMode(CH1_G_PIN, OUTPUT);
  pinMode(CH1_B_PIN, OUTPUT);

  // Initialize Channel 2 pins
  pinMode(CH2_R_PIN, OUTPUT);
  pinMode(CH2_G_PIN, OUTPUT);
  pinMode(CH2_B_PIN, OUTPUT);
  
}

void loop() {
  CH1 = CHSV(hue, SATURATION, BRIGHTNESS);
  CH2 = CHSV(hue + 127, SATURATION, BRIGHTNESS);
  hue += HUE_STEP;
  showColors();

  delay(1000 / SPEED_HZ);
}

void showColors() {
  analogWrite(CH1_R_PIN, CH1.r);
  analogWrite(CH1_G_PIN, CH1.g);
  analogWrite(CH1_B_PIN, CH1.b);

  analogWrite(CH2_R_PIN, CH2.r);
  analogWrite(CH2_G_PIN, CH2.g);
  analogWrite(CH2_B_PIN, CH2.b);
}
