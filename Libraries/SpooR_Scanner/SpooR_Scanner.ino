/*
   SpooR Scanning Program

   Description:
   This program demonstrates how to scan for all I2C devices connected
   to the I2C bus. It initializes the serial communication and uses
   the Wire library to scan for devices. For each device found, its
   I2C address is displayed on the Serial Monitor. This program can be
   used to detect I2C-based devices like sensors, displays, and other
   peripherals connected via I2C.

   Author: [SpooR]
   Date: [04/02/2025]
   Version: 1.0

   Hardware Requirements:
   - SpooR board
   - Any I2C-based devices (e.g., sensors, displays, actuators)
*/
#include <Wire.h>  // Include the Wire library for I2C communication

void setup() {
  // Initialize the I2C bus to start communication with I2C devices
  Wire.begin();

  // Begin serial communication at 9600 baud for displaying output on the Serial Monitor
  Serial.begin(9600);

  // Wait for the Serial Monitor to be ready before proceeding
  while (!Serial);

  // Display a welcome message to indicate the start of the program
  Serial.println("SpooR Robotics");
}

void loop() {
  byte error, address;
  int nDevices;

  // Print a message indicating that the scanning for I2C devices is starting
  Serial.println("SpooR Scanning...");

  // Initialize the count of devices found to 0
  nDevices = 0;

  // Loop through all possible I2C addresses from 8 to 126 (valid I2C addresses)
  for (address = 8; address < 127; address++ ) {
    // Begin I2C transmission with the current address
    Wire.beginTransmission(address);

    // End the transmission and capture the result (error code)
    error = Wire.endTransmission();

    // If error code 0 is returned, a device was found at this address
    if (error == 0) {
      // Display the I2C address of the found device in hexadecimal format
      Serial.print("I2C device found at address 0x");

      // If the address is less than 16 (single digit in hex), print a leading zero
      if (address < 16)
        Serial.print("0");

      // Print the device's address in hexadecimal
      Serial.print(address, HEX);
      Serial.println(" !");

      // Increment the count of found devices
      nDevices++;
    }
    // If error code 4 is returned, it indicates an unknown error at this address
    else if (error == 4) {
      // Print an unknown error message with the address where the error occurred
      Serial.print("Unknown error at address 0x");

      // If the address is less than 16, print a leading zero for formatting
      if (address < 16)
        Serial.print("0");

      // Print the address in hexadecimal format
      Serial.println(address, HEX);
    }
  }

  // If no devices were found (nDevices is still 0), print a message indicating no devices were detected
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    // Otherwise, print a message indicating that the scan is complete
    Serial.println("done\n");

  // Wait for 5 seconds before starting the next scan
  delay(2000);
}
