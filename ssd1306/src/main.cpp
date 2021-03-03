#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "WiFiSettings.h"

const char* ssid = WIFI_ESSID;
const char* password = WIFI_PASSWORD;

WiFiServer server(80);
Adafruit_SSD1306 display(128, 64, &Wire, -1);


void setup()  {                
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Connecting to WiFi...");
  display.display();
  delay(5000);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
    delay(500);

  display.setCursor(0, 18);
  display.println(WiFi.localIP());
  display.display();
  
  server.begin();
}

void loop() {}
