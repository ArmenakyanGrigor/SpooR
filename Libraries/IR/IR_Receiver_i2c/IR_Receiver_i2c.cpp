#include "IR_Receiver_i2c.h"

I2CDataPrinter::I2CDataPrinter(uint8_t slaveAddress)
    : _slaveAddress(slaveAddress), _address(0), _command(0), _flags(0) {}

void I2CDataPrinter::begin() {
    Wire.begin();
    Serial.begin(115200);
    Serial.println("I2C Master Ready");
}

bool I2CDataPrinter::readData() {
    Wire.requestFrom(_slaveAddress, 3);
    if (Wire.available() == 3) {
        _address = Wire.read();
        _command = Wire.read();
        _flags = Wire.read();
        return true;
    } else {
        return false;
    }
}

void I2CDataPrinter::printData() {
    Serial.print("Address=0x");
    Serial.print(_address, HEX);
    Serial.print(" Command=0x");
    Serial.print(_command, HEX);

    if (_flags & 0x02) {
        Serial.print(" Parity failed");
    }

    Serial.println();
}
