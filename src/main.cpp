#include <Arduino.h>
#define Baudrate 115200
#define LED_PIN 16
#define LCD_PIN 4

u_int16_t raw;
u_int16_t milivolts;

void setup() {
  Serial.begin(Baudrate);
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(LCD_PIN, INPUT);

}

void loop() {
  delay(500);
  raw = analogRead(LCD_PIN);
  float milivolts_calculated = raw/4095.0f*3100.0f;

  milivolts = analogReadMilliVolts(LCD_PIN);

  float measure_error = (milivolts_calculated - milivolts) / (float)milivolts * 100;

  Serial.printf("milivolts calculated: %.0f\n",milivolts_calculated);
  Serial.printf("milivolts: %d\n", milivolts);
  Serial.printf("measure_error: %.2f\%\n", measure_error);

}