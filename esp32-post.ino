#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "";
const char* password = "";
const char* postData = "Hello heunetik - ESP32";
HTTPClient http;

void setup() {
  Serial.begin(115200);
  delay(5000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  http.setReuse(true);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    http.begin("");
    http.addHeader("Content-Type", "text/plain");

    int httpResponseCode = http.POST(postData);
    if (httpResponseCode < 0) {
      Serial.print("HTTP client error: ");
    }
    Serial.println(httpResponseCode);
    
    http.end();
  } else {
    Serial.println("WiFi connection error!");
  }

  delay(10000);
}