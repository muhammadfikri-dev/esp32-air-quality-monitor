# 🍃 ESP32 Air Quality & Environmental Station

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform: ESP32](https://img.shields.io/badge/Platform-ESP32-blue.svg)](https://espressif.com/)
[![Sensor: PMS5003](https://img.shields.io/badge/Sensor-PMS5003%20Laser%20Dust-purple.svg)](#)
[![Portfolio: Laksanasoft](https://img.shields.io/badge/Portfolio-Laksanasoft-green.svg)](#)

A comprehensive indoor & outdoor air quality monitoring device using the **ESP32**. Computes real-time Air Quality Index (AQI), PM1.0, PM2.5, PM10 particulate matter concentration, CO2 equivalent / VOC levels, temperature, barometric pressure, and relative humidity.

---

## 📌 Measured Parameters

- **Particulate Matter (PMS5003):** PM1.0, PM2.5, and PM10 in $\mu g/m^3$.
- **Hazardous Gases & VOCs (MQ-135):** Carbon Dioxide ($CO_2$), Ammonia ($NH_3$), Benzene, and Smoke.
- **Atmospheric Conditions (BME280):** Temperature ($^\circ C$), Relative Humidity (%), and Barometric Pressure ($hPa$).
- **Local Visual Indicator:** 0.96\" I2C OLED display with real-time AQI health status and RGB alert LED.

---

## 🔌 Sensor Pinout

```
+------------------+---------------------+-------------------+
| ESP32 Pin        | Sensor Pin          | Description       |
+------------------+---------------------+-------------------+
| GPIO 16 (RX2)    | PMS5003 TX          | Laser PM UART     |
| GPIO 17 (TX2)    | PMS5003 RX          | Laser PM UART     |
| GPIO 21 (SDA)    | BME280 / OLED SDA   | I2C Data          |
| GPIO 22 (SCL)    | BME280 / OLED SCL   | I2C Clock         |
| GPIO 35 (ADC1)   | MQ-135 Analog A0    | Gas Analog In     |
| GPIO 25, 26, 27  | RGB Common Cathode  | AQI Color Alert   |
+------------------+---------------------+-------------------+
```

---

## 🚀 Setup & Flashing

1. Connect sensors as shown in the pinout table.
2. Install `Adafruit BME280`, `Adafruit SSD1306`, and `PMS Library`.
3. Open `esp32-air-quality-monitor.ino` and upload to ESP32.

---

## 📄 License
MIT License. Developed for **Laksanasoft Portfolio**.
