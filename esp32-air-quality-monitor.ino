/**
 * @file esp32-air-quality-monitor.ino
 * @brief ESP32 Multi-Sensor Environmental & AQI Monitor
 * @author Muhammad Fikri (Laksanasoft)
 * @license MIT
 */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_BME280 bme;

#define PIN_MQ135 35

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(10, 25);
  display.println("Laksanasoft AirQ");
  display.display();

  if (!bme.begin(0x76, &Wire)) {
    Serial.println("BME280 not detected, check wiring.");
  }
  delay(1500);
}

void loop() {
  float temp = bme.readTemperature();
  float hum = bme.readHumidity();
  float pres = bme.readPressure() / 100.0F;
  int mqRaw = analogRead(PIN_MQ135);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("== LAKSANASOFT AQI ==");
  display.setCursor(0, 16);
  display.printf("Temp : %.1f C\n", temp);
  display.printf("Hum  : %.1f %%\n", hum);
  display.printf("Pres : %.0f hPa\n", pres);
  display.printf("Gas Raw: %d\n", mqRaw);

  display.setCursor(0, 52);
  if (mqRaw < 1200) {
    display.println("Status: GOOD AIR [OK]");
  } else if (mqRaw < 2200) {
    display.println("Status: MODERATE [WARN]");
  } else {
    display.println("Status: UNHEALTHY [ALERT]");
  }
  display.display();

  delay(2000);
}
