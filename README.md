
# IoT Weather Monitoring System

An IoT-based Weather Monitoring System using **ESP8266 (NodeMCU)**.
The system measures **Temperature, Humidity, Air Quality (CO₂ concentration), and Pressure**, displaying the data on a **16x2 I2C LCD**, uploading it to **ThingSpeak Cloud**, and providing **mobile app access** for local and global weather monitoring.

---

## Features

* Monitors **Temperature & Humidity** using a DHT11 sensor
* Detects **Air Quality (CO₂ concentration)** using an MQ135 gas sensor
* Displays **simulated Pressure values** on LCD and uploads them to ThingSpeak
* Provides **real-time sensor data** on a 16x2 I2C LCD with progress bar visualization
* Uploads sensor readings to **ThingSpeak Cloud** for IoT integration
* Enables data access **from anywhere** via ThingSpeak Dashboard or mobile app
* Mobile app shows **local sensor data** and **global weather information**

---

## Components Used

* ESP8266 (NodeMCU)
* DHT11 Sensor – Temperature & Humidity
* MQ135 Gas Sensor – Air Quality (CO₂ ppm)
* 16x2 LCD Display (with I2C module)
* Rain Sensor 
* ThingSpeak Cloud Platform
* Mobile App (Flutter)

---

## Required Libraries

Install the following libraries in **Arduino IDE** before uploading the code:

* `Adafruit_Sensor.h`
* `DHT.h`
* `ESP8266WiFi.h`
* `LiquidCrystal_I2C.h`
* `MQ135.h`
* `Wire.h`

---

## Getting Started

### Installation Steps

1. Clone this repository:

   ```bash
   git clone https://github.com/your-username/iot-weather-monitoring.git
   cd iot-weather-monitoring
   ```
2. Open the `.ino` file in **Arduino IDE**
3. Install the required libraries via **Library Manager**
4. Update the following fields in the code:

   * WiFi **SSID** and **Password**
   * ThingSpeak **API Key**
5. Select the board: **NodeMCU 1.0 (ESP8266)**
6. Upload the code to the ESP8266
7. Launch the **mobile app** and connect to ThingSpeak API for local and global weather data

---

## ThingSpeak Data Fields

| Field | Description               |
| ----- | ------------------------- |
| 1     | Temperature (°C)          |
| 2     | Humidity (%)              |
| 3     | Air Quality (CO₂ ppm)     |
| 4     | Pressure (Pa – simulated) |

---

## LCD Display

The **16x2 I2C LCD** shows live sensor readings with **progress bar indicators** for:

* Temperature
* Humidity
* Air Quality
* Pressure

---

## Mobile App Features

* Displays **local sensor data** from the IoT system
* Shows **global weather information** for selected locations
* Syncs with **ThingSpeak Cloud** for real-time updates
* Provides **dashboard with graphs and indicators**

---

## Future Improvements

* Replace simulated pressure values with a **BMP180/BMP280 sensor**
* Integrate the **Rain Sensor** for rainfall monitoring
* Develop a **mobile/web dashboard** for advanced visualization
* Add **real-time alerts/notifications** for abnormal weather or air quality conditions

---


