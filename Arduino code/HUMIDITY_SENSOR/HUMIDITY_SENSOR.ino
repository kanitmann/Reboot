#include <dht11.h>

#define DHT11PIN 4

dht11 DHT11;
int sensorPin = A0; 
int sensorValue;  
int limit = 500; 
void setup() {
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}
void loop() {
  Serial.println();
  int chk = DHT11.read(DHT11PIN );
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  Serial.print("Temperature (C): ");
  Serial.println((float)DHT11.temperature, 2);
  
  sensorValue = analogRead(sensorPin); 
  Serial.print("Soil moisture reading : ");
  Serial.println(sensorValue);
  delay(2000);
 
  if (sensorValue>limit) {
  digitalWrite(13, HIGH); 
  }
  else {
  digitalWrite(13, LOW); 
  }
 
  delay(1000); 


}
