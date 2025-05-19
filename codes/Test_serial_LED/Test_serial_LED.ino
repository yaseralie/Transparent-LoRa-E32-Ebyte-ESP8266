#include <SoftwareSerial.h>

// Pin used in ESP8266, D5 and D6
#define LORA_RX 14
#define LORA_TX 12
#define LED_PIN 13  // Pin for LED

SoftwareSerial LoRaSerial(LORA_RX, LORA_TX);

void setup() {
  // Init serial
  Serial.begin(9600);
  LoRaSerial.begin(9600);

  // Init LED as output
  pinMode(LED_PIN, OUTPUT);

  // Turn ON LED initialize
  digitalWrite(LED_PIN, HIGH);

  Serial.println("ESP8266 and LoRa E32 are Ready!");
  delay(1000);
  //initialize sending message
  LoRaSerial.println("Start!!!");
}

void loop() {
  // Reads message from LoRa and display in Serial Monitor
  if (LoRaSerial.available()) {
    String message = LoRaSerial.readStringUntil('\n');
    Serial.println("Receive: " + message);

    // Mengubah status LED
    if (digitalRead(LED_PIN) == HIGH) {
      digitalWrite(LED_PIN, LOW);
    } else {
      digitalWrite(LED_PIN, HIGH);
    }
    delay(1000);
    // Sending a "Test" message via LoRa
    LoRaSerial.println("Test");
    Serial.println("Send: Test");
  }
}
