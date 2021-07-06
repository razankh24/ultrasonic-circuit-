#include <Wire.h>
int triggerPin = 4;
int echoPin = 6;
int potVal=0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Wire.begin(); 
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(echoPin);
  Wire.beginTransmission(9); 
  Wire.write(potVal);             
  Wire.endTransmission();    
  Wire.requestFrom(9, 6);    
  while (Wire.available()) { 
    char x = Wire.read(); 
    Serial.print(x);         
  }
  
  delay(500);
}