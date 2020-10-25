/*
Servo Potentiometer Project:
Use the input value from a potentiometer in order to control
a servo motor. And print the potentiometer values.
*/

//Include the Servo Library.
#include <Servo.h>
//Creating a servo object "myservo" from the class "Servo"
Servo myservo;
//Set potentiometer sensor to Analog Pin A0
const int pot = A0;

void setup()
{
  myservo.attach(11); //Set the servo to Digital Pin 11.
  pinMode(pot,INPUT); //Set pot to INPUT
  Serial.begin(9600);//Intialize Serial Communication
}

void loop()
{
  //Get the analog value from pot
  int pot_value = analogRead(pot);
  //Map the analog value from 0-1023 to 0-255
  pot_value = map(pot_value, 0, 1023, 0, 255);
  //Control the servo using the pot_value
  myservo.write(pot_value);
  //Print the pot_value
  Serial.println(pot_value);
  delay(50);
}
