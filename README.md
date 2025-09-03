IoT Weather Monitoring System

This project is an IoT-based Weather Monitoring System using ESP8266 (NodeMCU) that measures Temperature, Humidity, Air Quality (CO₂), and Pressure.
The data is displayed on a 16x2 I2C LCD and sent to ThingSpeak for remote monitoring and analysis.

Features

Reads Temperature & Humidity using DHT11 sensor

Measures Air Quality (CO₂ concentration) with MQ135 sensor

Simulated Pressure values displayed on LCD and uploaded to ThingSpeak

Real-time sensor values displayed on 16x2 I2C LCD with progress bars

IoT integration with ThingSpeak Cloud

Data accessible anywhere via ThingSpeak Dashboard

Components Used

ESP8266 (NodeMCU)

DHT11 Sensor – Temperature & Humidity

MQ135 Gas Sensor – Air Quality (CO₂ ppm)

16x2 LCD Display (I2C module)

Rain Sensor (defined but not used in code yet)

ThingSpeak Cloud Platform

Libraries Required

Make sure to install the following libraries in Arduino IDE:

Adafruit_Sensor.h

DHT.h

ESP8266WiFi.h

LiquidCrystal_I2C.h

MQ135.h

Wire.h

Getting Started
Installation

Clone the repository:

Open the .ino file in Arduino IDE

Install required libraries from Arduino Library Manager

Update the following in code:

WiFi SSID & Password

ThingSpeak API Key

Select NodeMCU 1.0 (ESP8266) board and upload

ThingSpeak Data Fields
Field	Data
Field 1	Temperature (°C)
Field 2	Humidity (%)
Field 3	Air Quality (ppm - CO₂)
Field 4	Pressure (Pa - simulated)
LCD Display

Shows live sensor values

Displays progress bars for:

Temperature

Humidity

Air Quality

Pressure

Future Improvements

Integrate actual pressure sensor (BMP180/BMP280) instead of simulated values

Enable rain sensor data logging

Create mobile/web app dashboard for visualization

Add alerts/notifications for abnormal air quality or weather changes
