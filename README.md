# 🌱 Plant Moisture Sensor – Arduino Project

This simple Arduino project monitors the moisture level of soil using a capacitive moisture sensor. If the soil is too dry, the Arduino will trigger a response (e.g., an LED alert, serial message, or future watering system).

## 📦 Project Overview

- Reads data from a capacitive moisture sensor
- Converts analog sensor values into a readable moisture level
- Indicates whether the plant needs water
- Designed for simplicity – just upload and run

## 🧰 Hardware Requirements

- Arduino Uno (or compatible board)
- Capacitive soil moisture sensor
- Jumper wires
- Breadboard (optional)
- LED (optional for visual alert)

## 🔧 Wiring

| Sensor Pin     | Connect To        |
|----------------|-------------------|
| VCC            | 5V on Arduino     |
| GND            | GND on Arduino    |
| AOUT (Analog)  | A0 on Arduino     |

*Optional:* Connect an LED to digital pin 13 with a resistor in series for a visual dryness alert.

## 🚀 Getting Started

1. Clone or download this repository.
2. Open the `.ino` file in the Arduino IDE.
3. Connect your Arduino and select the correct port/board.
4. Upload the code.
5. Open the Serial Monitor (9600 baud) to view moisture levels.

## 🧪 How It Works

- The sensor returns analog values depending on soil moisture.
  - **Dry soil** → Higher value
  - **Wet soil** → Lower value
- Threshold values can be adjusted in code based on your specific plant's needs.
