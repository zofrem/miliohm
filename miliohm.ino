#include <LiquidCrystal.h>
#include "LiquidCrystalChart.h"
#include <inttypes.h>
#include "BarChars.h"

LiquidCrystal* lcd = new LiquidCrystal(12, 11, 5, 4, 3, 2);
const uint8_t DISPLAY_BARS = 16;
const uint8_t DISPLAY_ROWS = 2;
BarChars* barChar =  new BarChars(*lcd);
LiquidCrystalChart* chartBar = new LiquidCrystalChart(*lcd, *barChar, 0, 0, 3, DISPLAY_BARS);

void setup() {
  pinMode(PC13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PC13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);              // wait for a second
  digitalWrite(PC13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
