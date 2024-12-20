// Temperature sensor
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 6
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// 7SegmetDisplay
#include <Arduino.h>
#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

// relay
#define relay 9

void setup() {
  Serial.begin(9600);
  sensors.begin();
  display.setBrightness(0x0f);
  pinMode(relay, OUTPUT);
}

void loop() {
  float tempC = sensors.getTempCByIndex(0);
  display.showNumberDec(tempC);
  Serial.println(tempC);
  if (tempC < 3){
    digitalWrite(relay, HIGH);
  }
  if (tempC < 7){
    digitalWrite(relay, LOW);
  }
  delay(1000);
}
