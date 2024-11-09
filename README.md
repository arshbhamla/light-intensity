# NJIT Classroom Lighting Assessment Project

## Overview
The purpose of this project is to see whether NJIT's classroom lighting meets the recommendations for learning environments. It will assess light levels and uniformity using data collected using a circuit and Arduino. 

## Timeline
- **Data Collection**: Mid-November
- **Analysis & Reporting:** By November 25, 2024
- **Final Report Submission:** December 2, 2024

## Hardware
The circuit uses the following pieces of hardware:
- **KY-018 Photoresistor Module:** Used to collect data light intensity 
- **Arduino Uno:** Receives analog voltage from module and sends lux calculation to computer

## Languages
- Python
- C++

## Dependencies
The C++ code uses the Arduino.h library. If using the Arduino IDE, this should be preinstalled, but if using another IDE, you will need to set up an Arduino Development environment to run the code. 

If you're using PlatformIO and VSCode like I am, the steps to run this code are below:
1) Install [Visual Studio Code](https://code.visualstudio.com/) and [PlatformIO](https://platformio.org/)
2) Clone project from Github and open in VSCode. 
3) Set up project using PlatformIO. The platformio.ini file should be automatically detected and configure the platform to run the code. 
4) If PlatformIO has not detected the code, you can create a new project from their home page, and move the files into there. Everything but the platformio.ini file will go into "src", and platformio.ini needs to replace the existing one.  