// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.

// modified by Andrew Sowers on 1/9/2016

#include <Servo.h> 
String readString;
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
int pos = 0;    // variable to store the servo position 
int ledPin = 5;

void setup() 
{ 
  pinMode(ledPin, OUTPUT);
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
  while(!Serial) {}
} 

void loop() 
{ 
  while (Serial.available() > 0) {
    delay(3);  //delay to allow buffer to fill 
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the string readString
  }

  if (readString.length() >0) {

    Serial.println("the state is:");
    Serial.println(readString);
    

    if (readString == "1") {
      pos = 120;
      digitalWrite(ledPin, HIGH);
    } else if (readString == "0"){
      pos = 10;
      digitalWrite(ledPin, LOW);
    }
    
    myservo.write(pos); //set servo position 
    readString="";
    delay(15);
  } 
}
