# 🏠 IoT Smart Home Automation System

## 📖 Project Overview
This is an **IoT-based Smart Home Automation System** developed during my IoT Internship at **Emertxe Information Technologies**. The system allows remote monitoring and control of home appliances using Arduino UNO and Blynk IoT platform.

## 🎯 Features
- **🌡️ Temperature Control** - Automatic heater/cooler control with safety cutoff
- **💡 Smart Lighting** - LDR-based automatic garden lights with PWM
- **💧 Water Management** - Remote tank level monitoring & valve control
- **📱 Blynk App Control** - Real-time remote monitoring and control
- **📊 LCD Display** - Local status display

## 🛠️ Hardware Components
- Arduino UNO
- Ethernet Shield
- LM35 Temperature Sensor
- LDR (Light Dependent Resistor)
- 16x2 I2C LCD Display
- Relay Module (Heater, Cooler, Inlet, Outlet)
- Serial Tank Sensor

## 💻 Software Used
- Arduino IDE
- Blynk IoT App
- PicsimLab (Simulation)
- Virtual Driver Connector

## 🔌 Circuit Diagram
![Circuit Diagram](circuit_image%20(1).png)

## 📁 Project Files
- `home_automation_blynk_controlled.ino` - Main Arduino code
- `SMART HOME AUTOMATION SYSTEM.pptx` - Project presentation
- `project_demo.mp4` - System demonstration video
- `circuit_image (1).png` - Circuit diagram

## 🔧 Installation & Setup
1. Clone this repository
2. Open Arduino IDE
3. Install required libraries:
   - Blynk
   - LiquidCrystal_I2C
   - Ethernet
4. Configure Blynk template with provided credentials
5. Upload code to Arduino
6. Set up hardware as per circuit diagram

## 🚀 How It Works
1. Sensors collect temperature, light, and water level data
2. Arduino processes the data
3. Ethernet shield connects to Blynk cloud
4. Users control devices via Blynk mobile app
5. LCD displays real-time status locally

## 📸 Output
Check the `project_demo.mp4` file to see the system in action!

## 👨‍💻 Developer
**Ram Axaykumar**  
IoT Intern at Emertxe Information Technologies

## 🙏 Acknowledgments
- **Emertxe Information Technologies** for the internship opportunity
- **Jayalaxmi N Dhanyal** for guidance and mentorship
- Blynk IoT platform for remote control capabilities

## 📜 License
This project is developed for educational purposes during Emertxe IoT Internship.
