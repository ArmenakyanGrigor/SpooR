#include <Arduino.h>
#include <Wire.h> // Include Wire library for I2C communication

#include "PinDefinitionsAndMore.h" // Set IR_RECEIVE_PIN for different CPU's
#include "TinyIRReceiver.hpp" // include the IR receiver code

#define I2C_SLAVE_ADDRESS 0x08 // Define the I2C slave address

uint8_t i2cBuffer[3]; // Buffer to hold the IR data to be sent via I2C

/*
 * Helper macro for getting a macro definition as string
 */
#if !defined(STR_HELPER)
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#endif

void setup() {
    Serial.begin(115200);
    Wire.begin(I2C_SLAVE_ADDRESS); // Initialize I2C as a slave with the defined address
    Wire.onRequest(requestEvent); // Register the request event handler

#if defined(__AVR_ATmega32U4__) || defined(SERIAL_PORT_USBVIRTUAL) || defined(SERIAL_USB) /*stm32duino*/|| defined(USBCON) /*STM32_stm32*/|| defined(SERIALUSB_PID) || defined(ARDUINO_attiny3217)
    delay(4000); // To be able to connect Serial monitor after reset or power up and before first print out. Do not wait for an attached Serial Monitor!
#endif
    // Just to know which program is running on my Arduino
#if defined(ESP8266) || defined(ESP32)
    Serial.println();
#endif
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_TINYIR));

    // Enables the interrupt generation on change of IR input signal
    if (!initPCIInterruptForTinyReceiver()) {
        Serial.println(F("No interrupt available for pin " STR(IR_RECEIVE_PIN))); // optimized out by the compiler, if not required :-)
    }
#if defined(USE_FAST_PROTOCOL)
    Serial.println(F("Ready to receive Fast IR signals at pin " STR(IR_RECEIVE_PIN)));
#else
    Serial.println(F("Ready to receive NEC IR signals at pin " STR(IR_RECEIVE_PIN)));
#endif
}

void loop() {
    if (TinyIRReceiverData.justWritten) {
        TinyIRReceiverData.justWritten = false;
#if !defined(USE_FAST_PROTOCOL)
        // We have no address at FAST protocol
        Serial.print(F("Address=0x"));
        Serial.print(TinyIRReceiverData.Address, HEX);
        Serial.print(' ');
#endif
        Serial.print(F("Command=0x"));
        Serial.print(TinyIRReceiverData.Command, HEX);
        if (TinyIRReceiverData.Flags == IRDATA_FLAGS_IS_REPEAT) {
            Serial.print(F(" Repeat"));
        }
        if (TinyIRReceiverData.Flags == IRDATA_FLAGS_PARITY_FAILED) {
            Serial.print(F(" Parity failed"));
#if !defined(USE_EXTENDED_NEC_PROTOCOL) && !defined(USE_ONKYO_PROTOCOL)
            Serial.print(F(", try USE_EXTENDED_NEC_PROTOCOL or USE_ONKYO_PROTOCOL"));
#endif
        }
        Serial.println();

        // Store the received data into the I2C buffer
        i2cBuffer[0] = TinyIRReceiverData.Address;
        i2cBuffer[1] = TinyIRReceiverData.Command;
        i2cBuffer[2] = TinyIRReceiverData.Flags;
    }
    /*
     * Put your code here
     */
}

/*
 * I2C request event handler
 * This function is called whenever a master device requests data from the slave
 */
void requestEvent() {
    Wire.write(i2cBuffer, sizeof(i2cBuffer)); // Send the IR data over I2C
}

/*
 * Optional code, if you require a callback
 */
#if defined(USE_CALLBACK_FOR_TINY_RECEIVER)
/*
 * This is the function, which is called if a complete frame was received
 * It runs in an ISR context with interrupts enabled, so functions like delay() etc. should work here
 */
#  if defined(ESP8266) || defined(ESP32)
IRAM_ATTR
#  endif

void handleReceivedTinyIRData() {
#  if defined(ARDUINO_ARCH_MBED) || defined(ESP32)
    /*
     * Printing is not allowed in ISR context for any kind of RTOS, so we use the slightly more complex,
     * but recommended way for handling a callback :-). Copy data for main loop.
     * For Mbed we get a kernel panic and "Error Message: Semaphore: 0x0, Not allowed in ISR context" for Serial.print()
     * for ESP32 we get a "Guru Meditation Error: Core  1 panic'ed" (we also have an RTOS running!)
     */
    // Do something useful here...
#  else
    // As an example, print very short output, since we are in an interrupt context and do not want to miss the next interrupts of the repeats coming soon
    printTinyReceiverResultMinimal(&Serial);
#  endif
}
#endif
