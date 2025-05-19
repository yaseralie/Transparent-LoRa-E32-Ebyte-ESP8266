#include <SoftwareSerial.h>

// Pin used in ESP8266, D5 and D6
#define LORA_RX 14
#define LORA_TX 12

SoftwareSerial LoRaSerial(LORA_RX, LORA_TX);

void setup() {
  // Init serial communication
  Serial.begin(9600);
  LoRaSerial.begin(9600);

  Serial.println("ESP8266 and LoRa E32 are Ready!");
}

void loop() {
  // Read message from Serial and send to LoRa
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    LoRaSerial.println(message);
    Serial.println("Send: " + message);
  }

  // Read message from LoRa and display in Serial Monitor
  if (LoRaSerial.available()) {
    String message = LoRaSerial.readStringUntil('\n');
    Serial.println("Receive: " + message);
  }
  delay(10);
}
