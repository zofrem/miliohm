#include <LiquidCrystal.h>
#include "LiquidCrystalChart.h"
#include <inttypes.h>
#include "LoopTimer.h"
#include "BarChars.h"

LiquidCrystal* lcd = new LiquidCrystal(PB3, PB4, PB6, PB7, PB8, PB9);
const uint8_t DISPLAY_BARS = 16;
const uint8_t DISPLAY_ROWS = 2;
BarChars* barChar =  new BarChars(*lcd);
LiquidCrystalChart* chartBar = new LiquidCrystalChart(*lcd, *barChar, 0, 0, 3, DISPLAY_BARS);
LoopTimer* backlightTimer = new LoopTimer(500000);  //10000
bool backlight = false;
bool firstRun = true;

void setup() 
{
  pinMode(PB11, OUTPUT);
  lcd->clear();
  lcd->begin(DISPLAY_BARS, DISPLAY_ROWS);
  lcd->setCursor(0, 0);
  lcd->print("miliohm");
  lcd->setCursor(0, 1);
  lcd->print("meter");
}

void loop() 
{
  backLightDelayOff();
  if(firstRun)
  {
    activBacklight();
    firstRun = false;
  }
}

void backLightDelayOff()
{
  if(backlightTimer->timer())
  {
    if(backlight)
    {
      backlight = false;
      digitalWrite(PB11, LOW);
    }
  }
}

void activBacklight()
{
  backlightTimer->resetTimer();
  if(!backlight)
  {
    backlight = true;
    digitalWrite(PB11, HIGH);
  }
}
