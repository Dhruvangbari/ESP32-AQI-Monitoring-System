# Air Quality Index (AQI) Monitoring System using ESP32 🌫️📊  
Measure the air. Understand the risk.

This project implements a **real-time Air Quality Index (AQI) monitoring system** using an **ESP32**, **MQ-135 air quality sensor**, visual indicators, an audible alarm, and a **16x2 LCD display**.

The system continuously monitors air quality and alerts users when pollution levels exceed safe limits.

Simple hardware. Meaningful data. Real awareness.

---

## 🧠 Project Overview
Air pollution can severely affect health, especially in indoor environments.  
This system measures air quality in real time and provides **instant feedback** using LEDs, a buzzer, and an LCD display.

### Working Flow

The ESP32 is used for its **high-resolution ADC** and future IoT expandability.

---

## ⚡ Key Features
- Continuous air quality monitoring
- High-resolution ESP32 ADC (0–4095)
- Adjustable air quality threshold
- Audible alert for poor air quality
- Visual indication using red & green LEDs
- Real-time sensor value display on LCD
- Clean, readable ESP32 code

Designed for **academic projects and demonstrations**.

---

## 🔧 Hardware Components
- ESP32 Development Board  
- MQ-135 Air Quality Sensor  
- Buzzer  
- Red LED (Bad air quality)  
- Green LED (Good air quality)  
- 16x2 LCD Display (Parallel mode)  
- Resistors and jumper wires  

⚠️ ESP32 works on **3.3V logic**. Ensure sensor output is ADC-safe.

---

## 🔌 Pin Connections

### MQ-135 Sensor
| MQ-135 Pin | ESP32 GPIO |
|-----------|------------|
| AO | GPIO 34 |
| VCC | 5V |
| GND | GND |

### Output Devices
| Device | ESP32 GPIO |
|------|-----------|
| Buzzer | GPIO 25 |
| Red LED | GPIO 26 |
| Green LED | GPIO 27 |

### LCD (16x2)
| LCD Pin | ESP32 GPIO |
|--------|------------|
| RS | 23 |
| EN | 22 |
| D4 | 21 |
| D5 | 19 |
| D6 | 18 |
| D7 | 5 |

---

## 💻 ESP32 Logic
- Reads analog value from MQ-135 sensor (0–4095)
- Displays air quality value on LCD
- Compares reading with a calibrated threshold
- Activates buzzer and red LED when air quality is bad
- Displays GOOD status using green LED otherwise

---

## ⚙️ Threshold Configuration
```cpp
int threshold = 2000; // Adjust after calibration
