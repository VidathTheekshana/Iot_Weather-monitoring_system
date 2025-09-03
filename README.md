#IoT Weather Monitoring System

This project is an IoT-based Weather Monitoring System built using ESP8266 (NodeMCU). It is designed to measure Temperature, Humidity, Air Quality (CO₂ concentration), and Pressure.
The collected data is displayed on a 16x2 I2C LCD and simultaneously uploaded to ThingSpeak Cloud for remote monitoring and analysis.

Features

Monitors Temperature and Humidity using a DHT11 sensor

Detects Air Quality (CO₂ concentration) using an MQ135 gas sensor

Displays simulated Pressure values on LCD and uploads to ThingSpeak

Provides real-time sensor data on a 16x2 I2C LCD with progress bar visualization

Uploads sensor readings to ThingSpeak Cloud for IoT integration

Enables data access from anywhere through the ThingSpeak Dashboard

Components Used

ESP8266 (NodeMCU)

DHT11 Sensor – Temperature & Humidity

MQ135 Gas Sensor – Air Quality (CO₂ ppm)

16x2 LCD Display (with I2C module)

Rain Sensor (defined in code but not currently used)

ThingSpeak Cloud Platform

Required Libraries

The following libraries must be installed in Arduino IDE before uploading the code:

Adafruit_Sensor.h

DHT.h

ESP8266WiFi.h

LiquidCrystal_I2C.h

MQ135.h

Wire.h

Getting Started
Installation Steps

Clone this repository:

git clone https://github.com/your-username/iot-weather-monitoring.git
cd iot-weather-monitoring


Open the .ino file in Arduino IDE

Install the required libraries via Library Manager

Update the following fields in the code:

WiFi SSID and Password

ThingSpeak API Key

Select the board: NodeMCU 1.0 (ESP8266)

Upload the code to the ESP8266

ThingSpeak Data Fields
Field	Description
Field 1	Temperature (°C)
Field 2	Humidity (%)
Field 3	Air Quality (CO₂ ppm)
Field 4	Pressure (Pa - simulated)
LCD Display

The 16x2 I2C LCD shows live sensor readings and includes progress bar indicators for:

Temperature

Humidity

Air Quality

Pressure

Future Improvements

Replace simulated pressure values with a BMP180/BMP280 pressure sensor

Integrate the rain sensor for rainfall monitoring

Develop a mobile or web dashboard for advanced visualization

Add real-time alerts/notifications for abnormal weather or air quality conditions
