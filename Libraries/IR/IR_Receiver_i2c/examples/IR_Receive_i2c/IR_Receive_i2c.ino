#include <IR_Receiver_i2c.h>

I2CDataPrinter dataPrinter(I2C_SLAVE_ADDRESS);

void setup() {
    dataPrinter.begin();
}

void loop() {
    if (dataPrinter.readData()) {
        dataPrinter.printData();
    } else {
        Serial.println("Error: expected 3 bytes");
    }

    delay(100);
}
