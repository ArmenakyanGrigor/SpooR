# SpooR Robotics

**SpooR Robotics** specializes in developing advanced robotics and CNC machines. Our GitHub repositories focus on robotics, providing libraries and firmware for our flagship robot, **SpooR**.

## SpooR Robot Overview
SpooR is a highly modular and programmable robot with three onboard microcontrollers:
- **ESP32**
- **Arduino Mega2560**
- **Raspberry Pi Zero W**

SpooR is designed with a custom **main board** that integrates various sensors and modules via **I2C communication**, making it a powerful platform for robotics applications.

### **Key Features**
- **I2C-Based Sensor Suite:**
  - VL53L0X (Time-of-Flight Sensor)
  - PCA9685 (PWM Driver)
  - AGS10 (Gas Sensor)
  - QMI8658A (IMU)
  - QMC5883 (Magnetometer)
  - BMP280 (Barometric Pressure Sensor)
  - ADS1115 (ADC)
  - AHT20 (Temperature & Humidity Sensor)
  - TCS34725 (Color Sensor)
  - IR Line Following Module
  - IR Remote Controller (I2C Communication)
  - Stepper Motor Control (I2C Communication)

- **Onboard Modules of the SpooR Main Board:**
  - DS3231S (Real-Time Clock)
  - PCF8574T (LCD Controller)
  - TCA9548 (I2C Multiplexer)
  - HT16K33 (LED Controller)
  - OLED Display
  - INA3221 (Current & Voltage Sensor)
  - 3 RGB LEDs
  - 3 Additional LEDs
  - 5 Programmable Buttons

- **Modular Design:** The main board acts as the **robot’s frame**. By adding a structural frame, SpooR can be transformed into a **car robot**.

## Getting Started
### **Requirements**
- **Hardware:**
  - SpooR Robot (Main Board + Sensors)
  - Supporting components (Motors, Batteries, etc.)

- **Software:**
  - Arduino IDE (for Mega2560 and ESP32)
  - Python (for Raspberry Pi Zero W)
  - STM32CubeIDE (if integrating additional STM32 boards)

### **Installation & Setup**
1. Clone this repository:
   ```bash
   git clone https://github.com/ArmenakyanGrigor/Spoor.git
   ```
2. Upload the firmware to the respective microcontrollers.
3. Connect the hardware and test the system using the provided libraries.

## Contributing
We welcome contributions! Feel free to submit pull requests or open issues for feature suggestions and bug reports.

## License
This project is open-source and available under the **MIT License**.

## Contact
For inquiries, support, or collaboration opportunities, reach out to us at **grigorarmenakyan@gmail.com
**

