/*
Arsh Bhamla
Project: Light Intensity Analysis
File Use: Receives data from photoresistor and calculates light intensity. 
*/

#include <Arduino.h>

const int analogPin = A2;
const int readPin = 9;
int time = 0;
float voltage;
float resistance;
float lightIntensity;

void setup() {
  pinMode(analogPin, INPUT);
  pinMode(readPin, OUTPUT);
  Serial.begin(9600);
}


float voltageConversion(int input){
  //Converts from the 0-1023 scale into the true voltage (mV)
  return input * 5.0 / 1023;
}

float resistorConversion(float voltage){
  //Voltage division
  int fixedResistance = 10000; //From sensor datasheet, in Ohms
  float fixedVoltage = 5000; //In milivolts
  return fixedResistance * voltage / (fixedVoltage - voltage);
}

float luxConversion(float resistance){
  //500 is an estimated constant between light intensity and resistance
  return 500 / resistance;
}

void loop() {
  int twoHours = 7200 + 60; //7200 is two hours, 60 seconds for maximum time of setup
  if(time < twoHours){
    //Serial.println(analogRead(analogPin));
    voltage = voltageConversion((int) analogRead(analogPin));
    //Serial.println("Voltage: " + (String)voltage);
    resistance = resistorConversion(voltage);
    //Serial.println("Resistance: " + (String)resistance);
    lightIntensity = luxConversion(resistance);
    Serial.println(lightIntensity);
    digitalWrite(readPin, HIGH);
    delay(100);
    digitalWrite(readPin, LOW);
    }
  else{
    digitalWrite(readPin, HIGH);
  }

  delay(900); //With the reading delay of 100ms, this is one second
  time++;
}