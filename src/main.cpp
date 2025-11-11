#include <Arduino.h>
#include <Arduino_GFX_Library.h>


#define PIN_NUM_LCD_CS     46
#define PIN_NUM_LCD_PCLK   16
#define PIN_NUM_LCD_DATA0  17
#define PIN_NUM_LCD_DATA1  18
#define PIN_NUM_LCD_DATA2  8
#define PIN_NUM_LCD_DATA3  3
#define PIN_NUM_LCD_RST    9

void setup() {
  // put your setup code here, to run once:

    Arduino_ESP32QSPI *qspi = new Arduino_ESP32QSPI(PIN_NUM_LCD_CS, 
                                                  PIN_NUM_LCD_PCLK,
                                                 PIN_NUM_LCD_DATA0,
                                                 PIN_NUM_LCD_DATA1,
                                                 PIN_NUM_LCD_DATA2,
                                                 PIN_NUM_LCD_DATA3,
                                              false);
    Arduino_CO5300 *display = new Arduino_CO5300(qspi, PIN_NUM_LCD_RST,0);
    display->begin();
    display->fillScreen(RED);
}

void loop() {
  // put your main code here, to run repeatedly:
}

