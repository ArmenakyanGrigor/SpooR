#ifndef I2CDATA_PRINTER_H
#define I2CDATA_PRINTER_H

#include <Wire.h>
#include <Arduino.h>

class I2CDataPrinter {
public:
    I2CDataPrinter(uint8_t slaveAddress);
    void begin();
    bool readData();
    void printData();

private:
    uint8_t _slaveAddress;
    uint8_t _address;
    uint8_t _command;
    uint8_t _flags;
};

#endif
