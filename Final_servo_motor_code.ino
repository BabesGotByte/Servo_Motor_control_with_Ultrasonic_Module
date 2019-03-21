#include <Servo.h>  // Include the Servo library
#include<ESP8266WiFi.h>
#define TRIGGER D6
#define ECHO    D8
int servoPin = 13;  // Declare the Servo pin

Servo Servo1;  // Create a servo object
void setup() {
Serial.begin(115200);
pinMode(TRIGGER, OUTPUT);
pinMode(ECHO, INPUT);
Serial.println("Hello");
Servo1.attach(servoPin); // We need to attach the servo to the used pin number

Servo1.write(0);
delay(1000);
}
void loop(){
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;
  
  Serial.print(distance);
  Serial.println("Centimeter:");
  delay(1000);

if(distance<30){
  Serial.println("open motor");
  Servo1.write(180); // Make servo go to 90 degrees
  delay(1000);
}
else{
  Serial.println("close motor");
  Servo1.write(0); // Make servo go to 0 degrees
  delay(1000);
}
}


