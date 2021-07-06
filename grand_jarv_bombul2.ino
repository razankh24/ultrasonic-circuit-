
#include <Wire.h>
int ledPin = 7;
int x = 0;
int distanceThreshold = 0;
int cm = 0;
int inches = 0;



void setup() {
  Serial.begin(9600);
  pinMode (ledPin, OUTPUT);

  Wire.begin(9); 
 
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}
void requestEvent()
{
  Wire.write("Hello ");
}

void receiveEvent(int bytes) {
  x = Wire.read();   
}
void loop() {
Serial.println(x);
distanceThreshold = 100;
  
  cm = 0.01723 *x );

  inches = (cm / 2.54);
  
if (cm > distanceThreshold)
{
   
    digitalWrite(7, LOW);
  }
  
  else  {
  
    digitalWrite(7, HIGH);
  }
  delay(10); 
} 

