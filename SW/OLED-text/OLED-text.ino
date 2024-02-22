/*
* This example code for LaskaKit 0.96" SSD1306 (SSD1315) OLED i2c display
* is used with ESP32 DEVkit board.
*
* SDA - GPIO21
* SCL - GPIO22
*
* Made by (c) laskakit.cz 2022
*
* Libraries
* https://github.com/adafruit/Adafruit-GFX-Library
* https://github.com/adafruit/Adafruit_SH110X
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>     // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SSD1306.h>

#define USUP_POWER_PIN 2  // uSUP power pin
#define DELAYTIME 1000
#define i2c_Address 0x3c

Adafruit_SSD1306 display(128, 64, &Wire, -1);


void setup() {
  Serial.begin(115200);
  while(!Serial);    // time to get serial running

  pinMode(USUP_POWER_PIN, OUTPUT);     // Set display power pin as output
  digitalWrite(USUP_POWER_PIN, HIGH);  // Turn on the display

           
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, i2c_Address)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  display.clearDisplay(); 
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setTextSize(1); 
}

void loop() {
  // put your main code here, to run repeatedly:
   display.setCursor(0,0);
   display.println((String)"Teplota: 25C");
   display.println((String)"Tlak: 950hPa");
   display.println((String)"Vlhkost: 65%");
   display.println((String)"Nadmorska vyska: 554m");
   display.display(); 
   delay(500);
   display.clearDisplay();
}  
