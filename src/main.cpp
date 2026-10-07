#include <Arduino.h>
#define Baudrate 115200
#define LED_BLUE_PIN 18
#define LED_RED_PIN 17
#define BUTTON_PIN 16
#define LCD_PIN 4

#define RED_MIN 2800
#define RED_MAX 3000

#define BLUE_MIN 3200
#define BLUE_MAX 3300


u_int16_t raw;

byte last_button_state = HIGH;
byte button_state = HIGH;
byte state = 0;


void setup() {
  Serial.begin(Baudrate);
  // put your setup code here, to run once:
  pinMode(LED_BLUE_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(LCD_PIN, INPUT);

}

void loop() {
  button_state = digitalRead(BUTTON_PIN);
  if(button_state == LOW && button_state != last_button_state)
  {
    state++;

    if(state%3 == 1)
    {
      digitalWrite(LED_RED_PIN, HIGH);
    }
    else if(state%3 == 2)
    {
      digitalWrite(LED_RED_PIN, LOW);
      digitalWrite(LED_BLUE_PIN, HIGH);
    }
    else
    {
      digitalWrite(LED_BLUE_PIN, LOW);
    }
  }
  last_button_state = button_state;
  delay(100);
  raw = analogRead(LCD_PIN);

  if(raw > RED_MIN && raw < RED_MAX)
  {
    Serial.println("RED");
  }
  else if(raw > BLUE_MIN && raw < BLUE_MAX)
  {
    Serial.println("BLUE");
  }
  else if(raw > 4090)
  {
    Serial.println("DARKNESS");
  }
}