#include "nokia5110esp.h"

Nokia5110ESP::Nokia5110ESP(uint8_t clk, uint8_t din, uint8_t dc, uint8_t ce, uint8_t rst, uint8_t bl)
{
  pinMode(mClkPin = clk, OUTPUT);
  pinMode(mDinPin = din, OUTPUT);
  pinMode(mDcPin = dc, OUTPUT);
  pinMode(mCePin = ce, OUTPUT);
  pinMode(mRstPin = rst, OUTPUT);
  pinMode(mBlPin = bl, OUTPUT);
  digitalWrite(mRstPin, LOW);
  digitalWrite(mRstPin, HIGH);
  command(CMD_FUNCTION_SET | FUNCTION_SET_EXTENDED);
  command(CMD_EXT_CONTRAST | EXT_CONTRAST_HIGH);
  command(CMD_EXT_TEMP_COEFICIENT | EXT_TEMP_COEFICIENT_HIGH);
  command(CMD_EXT_BIAS | EXT_BIAS_LOW);
  command(CMD_FUNCTION_SET | FUNCTION_SET_NORMAL);
  command(CMD_DISPLAY_MODE | DISPLAY_MODE_NORMAL); // Normal video
}


void Nokia5110ESP::backlight(uint8_t intensity)
{
  analogWrite(mBlPin, intensity);
}

void Nokia5110ESP::clear(uint8_t b)
{
  for(int i=0; i<504; i++)
    data(b);
}

void Nokia5110ESP::printxy(uint8_t x, uint8_t y, String str)
{
  command(0x80 | x);
  command(0x40 | y);
  for (int i = 0, length = str.length(); i < length; ++i) 
  {
    int c = str[i] - 0x20;
    for(int j = 0; j < 5; ++j)
      data(FONT[c][j]);
    data(0x00);
  }
}

void Nokia5110ESP::data(uint8_t b)
{
  digitalWrite(mDcPin, HIGH);
  digitalWrite(mCePin, LOW);
  shiftOut(mDinPin, mClkPin, MSBFIRST, b);
  digitalWrite(mCePin, HIGH);
}

void Nokia5110ESP::command(uint8_t b)
{
  digitalWrite(mDcPin, LOW);
  digitalWrite(mCePin, LOW);
  shiftOut(mDinPin, mClkPin, MSBFIRST, b);
  digitalWrite(mCePin, HIGH);
}

