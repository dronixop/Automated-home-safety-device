#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char ssid[] = "WifiName";
char pass[] = "WifiPassword";

// Blynk authentication token
char auth[] = "blynk_auth_token";

// Pins for sensors and actuators
#define MQ2_PIN A0  // Pin for MQ2 sensor
#define FLAME_PIN D1  // Pin for flame sensor
#define TEMP_PIN A1  // Pin for temperature sensor
#define MOTOR_PIN D2  // Pin for motor
#define SERVO_PIN D3  // Pin for servo
#define RELAY_PIN D5  // Pin for relay controlling pump

// Thresholds
const int MQ2_THRESHOLD = 500;  // Example threshold for MQ2 sensor
const int FLAME_THRESHOLD = 100;  // Example threshold for flame sensor

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(MQ2_PIN, INPUT);
  pinMode(FLAME_PIN, INPUT);
  pinMode(TEMP_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(MOTOR_PIN, LOW);  // Ensure motor starts off
  digitalWrite(SERVO_PIN, LOW);  // Ensure servo starts off
  digitalWrite(RELAY_PIN, LOW);  // Ensure relay starts off
}

void loop() {
  Blynk.run();

  int mq2Value = analogRead(MQ2_PIN);
  int flameValue = digitalRead(FLAME_PIN);
  int tempValue = analogRead(TEMP_PIN);

  // Check MQ2 sensor
  if (mq2Value > MQ2_THRESHOLD) {
    digitalWrite(MOTOR_PIN, HIGH);  // Turn on motor
    digitalWrite(SERVO_PIN, HIGH);  // Open door with servo
  } else {
    digitalWrite(MOTOR_PIN, LOW);   // Keep motor off
    digitalWrite(SERVO_PIN, LOW);   // Close door with servo
  }

  // Check flame and temperature sensors
  if (flameValue == HIGH && tempValue > 0) {
    // Fire detected
    digitalWrite(RELAY_PIN, HIGH);  // Turn on relay to activate pump
    Blynk.notify("Fire detected!"); // Send notification to Blynk
    Blynk.email("my_email@email.com", "Fire Alert", "Fire detected in your home!"); // Send email via Blynk
  } else {
    digitalWrite(RELAY_PIN, LOW);  // Keep relay off
  }

  // Send sensor readings to Blynk
  Blynk.virtualWrite(V1, mq2Value);  // Example: send MQ2 sensor value to V1 widget
  Blynk.virtualWrite(V2, flameValue);  // Example: send flame sensor value to V2 widget
  Blynk.virtualWrite(V3, tempValue);  // Example: send temperature sensor value to V3 widget

  delay(1000);  // Adjust delay as needed
}
