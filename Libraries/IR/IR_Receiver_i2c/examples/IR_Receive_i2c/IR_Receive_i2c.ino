/*
   IR Receiver I2C Library Example

   Description:
   This program interfaces with an I2C-based IR receiver module using
   the IR_Receiver_i2c library. It reads data from the I2C slave device
   and prints the received values to the serial monitor.

   Author: [SpooR]
   Date: [04/02/2025]
   Version: 1.0

   Hardware Requirements:
   - SpooR board 
   - IR Receiver module
*/

#include <IR_Receiver_i2c.h>  // Include the custom library for I2C-based IR receiver communication

// Create an instance of I2CDataPrinter, specifying the I2C slave address
I2CDataPrinter dataPrinter(I2C_SLAVE_ADDRESS);

void setup() {
  dataPrinter.begin();  // Initialize I2C communication with the IR receiver
}

void loop() {
  // Attempt to read data from the I2C slave device
  if (dataPrinter.readData()) {
    dataPrinter.printData();  // Print the received IR data if valid
  } else {
    Serial.println("Error: expected 3 bytes");  // Print an error message if data is incomplete
  }

  delay(100);  // Add a small delay to prevent excessive polling
}
