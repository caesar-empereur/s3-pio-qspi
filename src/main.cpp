#include <Arduino.h>
#include <Arduino_GFX_Library.h>

// #include "radar-old.h"
#include "gesture-rgb.h"
#include "receive-mpu.h"
#include "receive-mavlink.h"
#include "rgb-init.h"
// #include "spi-init.h"


// #define PIN_NUM_LCD_CS     46
// #define PIN_NUM_LCD_PCLK   16
// #define PIN_NUM_LCD_DATA0  17
// #define PIN_NUM_LCD_DATA1  18
// #define PIN_NUM_LCD_DATA2  8
// #define PIN_NUM_LCD_DATA3  3
// #define PIN_NUM_LCD_RST    9
ges_data_t ges_data;

void setup() {
  // put your setup code here, to run once:

    // Arduino_ESP32QSPI *qspi = new Arduino_ESP32QSPI(PIN_NUM_LCD_CS, 
    //                                               PIN_NUM_LCD_PCLK,
    //                                              PIN_NUM_LCD_DATA0,
    //                                              PIN_NUM_LCD_DATA1,
    //                                              PIN_NUM_LCD_DATA2,
    //                                              PIN_NUM_LCD_DATA3,
    //                                           false);
    // Arduino_CO5300 *display = new Arduino_CO5300(qspi, PIN_NUM_LCD_RST,0);
    // display->begin();
    // display->fillScreen(RED);


    Serial.begin(115200);
    // Serial1.begin(115200);
    Serial2.begin(115200);
    initDisplay();
    gestureInit(0,0);

    mpu_init();
}

void loop() {
  // put your main code here, to run repeatedly:
    drawGestureByData(2, ges_data, 0, 0);
}


void serialEvent2(){
    ges_data = receive_parse_mpu();
}
