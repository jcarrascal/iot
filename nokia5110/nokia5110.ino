#include "nokia5110esp.h"

Nokia5110ESP screen = Nokia5110ESP();

void setup() {
}

void loop() {
  textDemo();
  backlightDemo();
}

void textDemo() {
  screen.clear();
  screen.printxy(0, 0, "Hello, world!");
  delay(1000);
  screen.printxy(2, 1, "Hello, world!");
  delay(1000);
  screen.printxy(3, 2, "Hello, world!");
  delay(1000);
  screen.printxy(5, 3, "Hello, world!");
  delay(1000);
  screen.printxy(6, 4, "Hello, world!");
  delay(1000);
  screen.printxy(8, 5, "Hello, world!");
  delay(1000);
}

void backlightDemo() {
  screen.backlight(BL_HIGH);
  delay(1000);
  screen.backlight(BL_MEDIUM);
  delay(1000);
  screen.backlight(BL_OFF);
  delay(1000);
}

