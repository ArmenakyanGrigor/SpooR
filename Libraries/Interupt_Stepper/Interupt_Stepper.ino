#include <Arduino.h>

// Pin definitions
#define STEP_PIN PB3
#define DIR_PIN PA15
#define ENABLE_PIN PB4


volatile uint32_t stepperSpeed = 100; // Speed of the stepper motor in steps per second

HardwareTimer timer(TIM2);

void setup() {
  // Set pin modes
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  // Enable the driver
  digitalWrite(ENABLE_PIN, LOW); // Active low

  // Set direction
  digitalWrite(DIR_PIN, HIGH); // Adjust as needed (HIGH or LOW)

  // Configure the timer
  setupTimer();
}

void setupTimer() {
  // Set the timer's overflow frequency
  timer.setOverflow(stepperSpeed, MICROSEC_FORMAT);

  // Attach interrupt handler to timer overflow
  timer.attachInterrupt(timerISR);

  // Start the timer
  timer.resume();
}

void timerISR() {
 inInterupt();
}

void loop() {

}


void inInterupt() {
  digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));
}
