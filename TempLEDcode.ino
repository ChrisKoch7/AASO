#include <OneWire.h>
#include <DallasTemperature.h>
 
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
 
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
}
int led1 = 5;
int led2 = 6;
int led3 = 9;
int led4 = 10;
int led5 = 11;
 
 
void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");

  Serial.print("Temperature is: ");
  Serial.print(sensors.getTempCByIndex(0));
  double temp = sensors.getTempCByIndex(0); // Why "byIndex"?

  if (temp >= 23) {
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, 255);
    analogWrite(led4, 255);
    analogWrite(led5, 255);
  } 
  else  if (temp >= 22.5) {
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, 255);
    analogWrite(led4, 255);
    analogWrite(led5, 50);
  } 
  else if (temp >= 22) {
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, 255);
    analogWrite(led4, 255);
    analogWrite(led5, LOW);
  } 
  else  if (temp >= 21.5) {
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, 255);
    analogWrite(led4, 50);
    analogWrite(led5, LOW);
  } 
  else if (temp >= 21) {
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, 255);
    analogWrite(led4, LOW);
    analogWrite(led5, LOW);
  } 
  else  if (temp >= 20.5) {
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, 50);
    analogWrite(led4, LOW);
    analogWrite(led5, LOW);
  } 
  else if (temp >= 20) {
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, LOW);
    analogWrite(led4, LOW);
    analogWrite(led5, LOW);
  } 
  else  if (temp >= 19.5) {
    analogWrite(led1, 255);
    analogWrite(led2, 50);
    analogWrite(led3, LOW);
    analogWrite(led4, LOW);
    analogWrite(led5, LOW);
  } 
  else if (temp >= 19) {
    analogWrite(led1, 255);
    analogWrite(led2, LOW);
    analogWrite(led3, LOW);
    analogWrite(led4, LOW);
    analogWrite(led5, LOW);
  } 
  else if (temp >= 18.5) {
    analogWrite(led1, 50);
    analogWrite(led2, LOW);
    analogWrite(led3, LOW);
    analogWrite(led4, LOW);
    analogWrite(led5, LOW);
  } 
  else {
    analogWrite(led1, LOW);
    analogWrite(led2, LOW);
    analogWrite(led3, LOW);
    analogWrite(led4, LOW);
    analogWrite(led5, LOW);
  }
  
  
    // You can have more than one IC on the same bus. 
    // 0 refers to the first IC on the wire
    delay(500);
}
