#include <Servo.h>
#include <String.h>
int servoPin = 6;
int throttlePin = 3;
int Message;
String message;
String angle;
String throttle;
double ang;
//I considered renaming thr to appa in reference to Avatar: The Last Airbender.
double thr;
Servo Rudder;

void setup() {
  // put your setup code here, to run once:
  Rudder.attach(servoPin);
  Rudder.write(90);
  pinMode(throttlePin,OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    Message = Serial.parseInt();
    message = String(Message);
    angle = message.substring(0,message.length()-2);//This method has been tested and approved.
    throttle = message.substring(message.length()-2);
    ang = angle.toInt();
    thr = throttle.toInt();
    Rudder.write(ang);
    analogWrite(throttlePin,((thr/99)*255));
  }
}

    
