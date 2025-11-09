# IoT-Based Underground Cable Fault Detection System

## Overview
This project aims to **detect and locate faults in underground power cables** using an **Arduino UNO microcontroller**, **IoT (ESP8266)**, and the principle of **Ohm’s Law**.  
When a fault (short or open circuit) occurs, the system calculates its **distance from the base station** and displays it on an **LCD** while simultaneously sending **real-time alerts via Blynk Cloud**.

This automation helps reduce human effort and fault detection time, ensuring **efficient maintenance** of underground electrical networks.


## Features
-  Real-time detection of underground cable faults  
-  Fault distance calculation based on voltage drop  
-  Visual display using 16x2 LCD screen  
-  Buzzer alerts for immediate response  
-  IoT-enabled monitoring via **Blynk Cloud**  
-  Works with **three-phase** simulated cable connections  


## Working Principle
The system works on **Ohm’s Law (V = IR)**.  
At the feeder end, when DC voltage is applied, the current changes according to the distance of the fault.  
This variation is read by the **Arduino UNO’s ADC (Analog to Digital Converter)** and processed to determine the **fault distance (in kilometers)**.


### Fault Types Detected:
- Open Circuit Fault  
- Short Circuit Fault  
  - Line-to-Ground (L-G)
  - Line-to-Line (L-L)

The calculated fault distance is displayed on the LCD and simultaneously transmitted to the **Blynk IoT Cloud** for live tracking.


## Hardware Components
| Component | Description |
|------------|-------------|
| **Arduino UNO** | Main controller for fault detection logic |
| **ESP8266 NodeMCU** | Sends real-time data to the Blynk IoT Cloud |
| **Relays (3-channel)** | Controls and simulates each cable phase |
| **Resistors** | Represent cable resistance per kilometer |
| **Buzzer & LED** | Alert system for detected faults |
| **16x2 LCD Display** | Displays fault distance and type |
| **Power Supply (12V Stepdown Transformer)** | Provides system power |
| **Switches (SPDT)** | Used to manually simulate cable faults |


## Software Requirements
- **Arduino IDE v1.8+** – for writing and uploading the code  
- **Blynk IoT App / Web Dashboard** – for real-time data monitoring  
- **C / C++ Programming Language (Embedded)**  
- **Proteus (optional)** – for circuit simulation and testing  


## IoT Integration
This project uses **Blynk 2.0 Cloud** to display real-time updates on a mobile or web dashboard.  
Users can:
- Monitor fault status (OK / FAULT)  
- View exact distance of the fault  
- Receive push notifications instantly  


## Circuit Block Diagram
Power Supply → Arduino UNO → Relays → Cable Lines → Switches → LCD + Buzzer + ESP8266 → Blynk Cloud


## Results
- Accurate fault distance detection displayed on LCD  
- Real-time IoT alert via Blynk mobile app  
- Quick identification of faulty phase line  
- Reduced maintenance and detection time  

