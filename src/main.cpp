#include <Arduino.h>
#define Baudrate 115200
#define LED_RED_OUT 15
#define LED_BLUE_OUT 16
#define BUTTON_PIN 17
#define BOOT_BUTTON 0

u_int8_t buttonState = HIGH;
u_int8_t bootButtonState = HIGH;

void setup() {
  Serial.begin(Baudrate);
  Serial.println("Hello world!");
  // put your setup code here, to run once:
  pinMode(LED_RED_OUT, OUTPUT);
  pinMode(LED_BLUE_OUT, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BOOT_BUTTON, INPUT_PULLUP);

}

void loop() {
  delay(25);
  buttonState = digitalRead(BUTTON_PIN);
  bootButtonState = digitalRead(BOOT_BUTTON);

  u_int8_t selectedMode = buttonState ? bootButtonState ? 0 : 2 : 1;
  if(selectedMode == 0)
  {
    digitalWrite(LED_BLUE_OUT, LOW);
    digitalWrite(LED_RED_OUT, LOW);
  }
  if(selectedMode == 1)
  {
    digitalWrite(LED_BLUE_OUT, HIGH);
    digitalWrite(LED_RED_OUT, HIGH);
    Serial.println("Red");

    delay(200);


    digitalWrite(LED_RED_OUT, LOW);
    digitalWrite(LED_BLUE_OUT, LOW);

    Serial.println("Blue");

    delay(200);
  }
  if(selectedMode == 2)
  {
    digitalWrite(LED_BLUE_OUT, HIGH);
    digitalWrite(LED_RED_OUT, LOW);

    delay(1000);

    digitalWrite(LED_BLUE_OUT, LOW);
    digitalWrite(LED_RED_OUT, HIGH);

    delay(1000);
  }
}