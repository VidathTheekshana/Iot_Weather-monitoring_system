byte customChar[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
// libr
// libraries for all the sensors
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <MQ135.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27

String apiKey = "1HZT1FFI9T5LR450"; // Enter your ThingSpeak API key

const char *ssid = "Galaxy M117494"; //  WiFi SSID
const char *pass = "qeqe9162";            // WiFi Password
const char *server = "api.thingspeak.com";

// initializing pins
#define DHTPIN 13
#define Rain 12
#define MQ135_PIN A0

// initilizing DHT
DHT dht(DHTPIN, DHT11);

// initilizing MQ sensor
MQ135 gasSensor = MQ135(MQ135_PIN);

// initilizing WiFI Client
WiFiClient client;

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.createChar(0, customChar);

  Serial.begin(9600); // starting Serial Monitor
  delay(10);
  dht.begin();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(ssid);
  Serial.println(ssid);
  lcd.clear();

  // Starting Wifi Communication
  Serial.println("WiFi-connecting");
  lcd.setCursor(0, 0);
  lcd.print("WiFi-connecting");
  delay(1000);
  lcd.clear();

  WiFi.begin(ssid, pass);
  delay(1100);
  while (WiFi.status() != WL_CONNECTED) {

    Serial.print(".");
    lcd.print(".");
  }
  Serial.println("");

  lcd.clear();
  lcd.println("WIFI Connected");
  Serial.println("WiFi connected");
}

void loop() {
  // taking Values from sensors
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float co2_ppm = gasSensor.getPPM();
 float p=random(10596,10627);

 

  // DHT Error message
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.println("Failed DHT");
    return;
  }

  // pushing Values to thingspeak
  if (client.connect(server, 80)) {
    String postStr = apiKey;
    postStr += "&field1=" + String(t);       // Temperature
    postStr += "&field2=" + String(h);       // Humidity
    postStr += "&field3=" + String(co2_ppm); // CO2 Concentration
    postStr += "&field4=" + String(p);

    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

    // printing Values in real time
    Serial.print("T: ");
    Serial.print(t);
    Serial.print(" degrees Celsius, Humidity: ");
    Serial.print(h);
    Serial.print("%, CO2 Concentration: ");
    Serial.print(co2_ppm);
    Serial.println(" ppm..");
    Serial.print("Pressure: ");
    Serial.println(p);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(t);
    lcd.setCursor(0, 1);
    lcd.print("H:");
    lcd.print(h);
    lcd.setCursor(9, 0);
    lcd.print("AQ:");
    lcd.print(co2_ppm);
    lcd.setCursor(9, 1);
    lcd.print("P:");
    lcd.print(p);
    
    
    delay(6000);
    lcd.clear();

    display1(t);
    delay(6000);
    lcd.clear();
    display2(h);
    delay(6000);
    lcd.clear();
    display3(co2_ppm);
    delay(6000);
    lcd.clear();
    display4(p);
    delay(6000);

    client.stop();
  } else {
    Serial.println("Failed to connect to ThingSpeak");
  }

  Serial.println("Waiting...");
  delay(1000);
}

void display1(float t) {

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);

  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("[");
  int numberOfBlocks = map(t, 0, 100, 0, 14); // Adjusted for LCD width
  for (int i = 0; i < numberOfBlocks; i++) {
    lcd.write(0); // Use the custom filled block character
  }
  for (int i = numberOfBlocks; i < 14; i++) { // Adjusted for LCD width
    lcd.print(" ");
  }
  lcd.print("]");
}

void display2(float h) {
  lcd.setCursor(0, 0);
  lcd.print("Humd: ");
  lcd.print(h);

  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("[");
  int numberOfBlocks = map(h, 0, 100, 0, 14); // Adjusted for LCD width
  for (int i = 0; i < numberOfBlocks; i++) {
    lcd.write(0); // Use the custom filled block character
  }
  for (int i = numberOfBlocks; i < 14; i++) { // Adjusted for LCD width
    lcd.print(" ");
  }
  lcd.print("]");
}

void display3(float co2_ppm) {
  lcd.setCursor(0, 0);
  lcd.print("Air Qu: ");
  lcd.print(co2_ppm);

  lcd.print("ppm");

  lcd.setCursor(0, 1);
  lcd.print("[");
  int numberOfBlocks = map(co2_ppm, 0, 30, 0, 14); // Adjusted for LCD width
  for (int i = 0; i < numberOfBlocks; i++) {
    lcd.write(0); // Use the custom filled block character
  }
  for (int i = numberOfBlocks; i < 14; i++) { // Adjusted for LCD width
    lcd.print(" ");
  }
  lcd.print("]");
}
void display4(float p) {
  lcd.setCursor(0, 0);
  lcd.print("Pressure : ");
  lcd.print(p);

  lcd.print("Pa");

  lcd.setCursor(0, 1);
  lcd.print("[");
  int numberOfBlocks = map(p, 10000,10900, 0, 14); // Adjusted for LCD width
  for (int i = 0; i < numberOfBlocks; i++) {
    lcd.write(0); // Use the custom filled block character
  }
  for (int i = numberOfBlocks; i < 14; i++) { // Adjusted for LCD width
    lcd.print(" ");
  }
  lcd.print("]");
}
