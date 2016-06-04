#ifndef NOKIA5110ESP_H
#define NOKIA5110ESP_H

#include <cstdint>
#include <string>
#include <Arduino.h>
#include "font.h"

#define CMD_FUNCTION_SET      (0x20)
#define FUNCTION_SET_NORMAL   (0x00)
#define FUNCTION_SET_EXTENDED (0x01)

#define CMD_DISPLAY_MODE     (0x08)
#define DISPLAY_MODE_BLANK   (0x00)
#define DISPLAY_MODE_NORMAL  (0x04)
#define DISPLAY_MODE_ALL_ON  (0x01)
#define DISPLAY_MODE_INVERSE (0x05)

#define CMD_EXT_CONTRAST  (0x80)
#define EXT_CONTRAST_HIGH (0x4F)
#define EXT_CONTRAST_LOW  (0x3F)

#define CMD_EXT_TEMP_COEFICIENT  (0x04)
#define EXT_TEMP_COEFICIENT_LOW  (0x00)
#define EXT_TEMP_COEFICIENT_HIGH (0x03)

#define CMD_EXT_BIAS  (0x10)
#define EXT_BIAS_LOW  (0x00)
#define EXT_BIAS_HIGH (0x07)

#define BL_HIGH   (255)
#define BL_MEDIUM (127)
#define BL_OFF    (0)

/**
 * Controls Nokia 5110 LCD screens using ESP8266, inspired by Julian Ilett's excellent series
 * on how to drive this screen. Check it out at:
 * https://www.youtube.com/playlist?list=PLjzGSu1yGFjXWp5F4BPJg4ZJFbJcWeRzk
 * 
 * The default connections are as follows:
 * #define CLK D0
 * #define DIN D1
 * #define DC  D2
 * #define CE  D3
 * #define RST D4
 * #define BL  D5
 * 
 * The backlight pin (BL) is optional as you could also connect it to any 3.3 output and save a pin.
 */
class Nokia5110ESP
{
  uint8_t mClkPin, mDinPin, mDcPin, mCePin, mRstPin, mBlPin;

public:
  Nokia5110ESP(uint8_t clk=D0, uint8_t din=D1, uint8_t dc=D2, uint8_t ce=D3, uint8_t rst=D4, uint8_t bl=D5);
  void backlight(uint8_t intensity);
  void data(uint8_t b);
  void command(uint8_t b);
  void clear(uint8_t b = 0x00);
  void printxy(uint8_t x, uint8_t y, String str);
};

#endif

