/*
   SpooR_LCD Library Example

   Description:
   This program demonstrates how to interface with an I2C-based LCD
   using the SpooR_LCD library. It initializes the LCD, turns on 
   the backlight, and displays a message with custom text on a 16x2 display.

   Author: [SpooR]
   Date: [04/02/2025]
   Version: 1.0

   Hardware Requirements:
   - SpooR board 
   - I2C-based 16x2 LCD display
*/

#include <SpooR_LCD.h>  // Include the SpooR_LCD library for controlling the LCD

// Create an instance of the SpooR_LCD class, specifying the I2C address and screen size
SpooR_LCD lcd(0x27, 16, 2);  // LCD address 0x27, 16 columns, 2 rows

void setup() {
  lcd.init();             // Initialize the LCD
  lcd.backlight();        // Turn on the backlight of the LCD
  lcd.setCursor(3, 0);    // Set the cursor to column 3, row 0 (the first row)
  lcd.print("Hello, world!");  // Display "Hello, world!" on the first row
  lcd.setCursor(1, 1);    // Set the cursor to column 1, row 1 (the second row)
  lcd.print("SpooR Robotics");  // Display "SpooR Robotics" on the second row
}

void loop() {
  // No code here since this program only displays a message once during setup.
}
