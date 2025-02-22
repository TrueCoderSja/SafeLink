#include "server.h"
#include "LoRaHandler.h"

#if defined(ESP8266)
  ESP8266WebServer server(80);
#elif defined(ESP32)
  WebServer server(80);
#endif

const char *ssid = "ESP_AP";
const char *password = "12345678";

String receivedLoRaData = "Waiting for data...";

void setupWiFi() {
  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void handleRoot() {
  server.send(200, "text/html", "<h1>ESP Web Server</h1><p>Welcome!</p>");
}

void loopLoRaReceiver() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    receivedLoRaData = ""; // Clear old data
    while (LoRa.available()) {
      receivedLoRaData += (char)LoRa.read();
    }
    Serial.println("Received LoRa: " + receivedLoRaData);
  }
}


void handleLoRaData() {
  server.send(200, "text/plain", receivedLoRaData);
}

void setupServer() {
  setupWiFi();
  initLoRa();
  
  server.on("/", handleRoot);
  server.on("/loradata", handleLoRaData);

  server.begin();
  Serial.println("Web server started.");
}

void handleClientRequests() {
  server.handleClient();
  loopLoRaReceiver();
}
