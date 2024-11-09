/*
Arsh Bhamla
Project: Light Intensity Analysis
File Use: Receives data from photoresistor and calculates light intensity. 
*/

#include <Arduino.h>

const int analogPin = A5;
int time = 0;
float voltage;
float resistance;
float lightIntensity;

void setup() {
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}


float voltageConversion(int input){
  //Converts from the 0-1023 scale into the true voltage (mV)
  return input * 5.0 * 1000 / 1023;
}

float resistorConversion(float voltage){
  //Derived from the voltage divider rule
  int fixedResistance = 10000; //From sensor datasheet, in Ohms
  float fixedVoltage = 5000; //In milivolts
  return fixedResistance * voltage / (fixedVoltage - voltage);
}

float luxConversion(float resistance){
  //500 is an estimated constant between light intensity and resistance
  return 500 / resistance;
}

void loop() {
  int twoHours = 7200 + 20; //7200 is two hours, 20 seconds for maximum time of setup
  if(time < twoHours){
    voltage = voltageConversion( (int) analogRead(analogPin) );
    resistance = resistorConversion(voltage);
    lightIntensity = luxConversion(resistance);
    Serial.println(lightIntensity);
  }

  delay(1000);
  time++;
}

