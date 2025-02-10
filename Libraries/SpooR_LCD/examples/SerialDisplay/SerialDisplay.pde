/*
   Serial to SpooR_LCD Display Example

   Description:
   This program demonstrates how to read data from the serial port
   and display it on an I2C-based LCD. When characters are received
   over the serial port, they are displayed on the LCD screen in real-time.

   Author: [SpooR]
   Date: [04/02/2025]
   Version: 1.0

   Hardware Requirements:
   - SpooR board 
   - I2C-based 16x2 LCD display
*/

#include <Wire.h>                // Include the Wire library for I2C communication
#include <SpooR_LCD.h>    // Include the SpooR_LCD library for LCD control

// Initialize the LCD with the I2C address 0x27 and a 16x2 display
SpooR_LCD lcd(0x27, 16, 2);

void setup() {
  lcd.init();                   // Initialize the LCD
  lcd.backlight();              // Turn on the LCD backlight
  Serial.begin(9600);           // Start serial communication at 9600 baud
}

void loop() {
  // When characters are available on the serial port...
  if (Serial.available()) {
    // Wait a bit to ensure the entire message has arrived
    delay(100);
    
    // Clear the LCD screen to prepare for new data
    lcd.clear();
    
    // Read all available characters from the serial port
    while (Serial.available() > 0) {
      // Display each character on the LCD
      lcd.write(Serial.read());
    }
  }
}
