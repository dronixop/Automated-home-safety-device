# Automated-Home-Safety-Device

## Overview

This project involves creating a home safety monitoring system using ESP8266 microcontroller, various sensors, and Blynk for real-time monitoring and control. The system monitors gas levels (LPG, CO, smoke), temperature, and detects flame using sensors. In case of an emergency, such as fire detection, it activates safety measures like controlling a motor, opening a door with a servo, and activating a pump for a sprinkler system using a relay.

## Components Used

- **ESP8266**: Microcontroller for IoT connectivity.
- **Sensors**:
  - MQ2 Sensor: Detects LPG, CO, and smoke levels.
  - Flame Sensor: Detects flame presence.
  - Temperature Sensor: Monitors ambient temperature.
- **Actuators**:
  - Motor: Controls window opening/closing.
  - Servo: Opens/closes the door.
  - Relay: Controls the pump for the sprinkler system.
- **Blynk App**: Used for real-time monitoring and control via the internet.

## Setup Instructions

1. **Hardware Setup**:
   - Connect the sensors (MQ2, Flame, Temperature) to the ESP8266 as per the circuit diagram.
   - Attach actuators (Motor, Servo) and relay for the pump as indicated in the setup.

2. **Software Setup**:
   - Install Arduino IDE and necessary libraries for ESP8266 development.
   - Upload the provided Arduino sketch (`home_safety.ino`) to the ESP8266.

3. **Blynk Configuration**:
   - Create a Blynk account and project.
   - Obtain the authentication token and update it in the Arduino sketch.
   - Set up Blynk widgets to visualize sensor data and control actuators.

## Operation

- **System Initialization**: Upon startup, the system initializes sensors, actuators, and connects to WiFi and Blynk.
  
- **Monitoring Sensors**: Continuously reads data from MQ2, Flame, and Temperature sensors.
  
- **Emergency Response**:
  - **Gas/Smoke Detection**: If MQ2 sensor detects hazardous levels, it activates the motor to open windows for ventilation.
  - **Fire Detection**: If both Flame and Temperature sensors detect a fire, the system activates the pump via relay for the sprinkler system, sends alerts to Blynk, and emails notifications.
