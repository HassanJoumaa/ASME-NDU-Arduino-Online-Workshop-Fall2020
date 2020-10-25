/*
LCD-Ultrasonic-Project
This program will read the distance from an ultrasonic sensor 
in "cm" and will print out the distance to the LCD screen.
Additionally, it will use a buzzer to warn the user if there 
are any obstacles near as follows:
1) If the distance<=50, buzz for 2 seconds.
2) If the distance<=35, buzz for 1 second.
3) If the distance<=20, buzz for 0.25 seconds.

Pin-Layout for LCD:
LCD RS pin to digital pin 2

LCD Enable pin to digital pin 3

LCD D4 pin to digital pin 4

LCD D5 pin to digital pin 5

LCD D6 pin to digital pin 6

LCD D7 pin to digital pin 7

LCD R/W pin to GND

LCD GND pin to GND

LCD VCC pin to 5V

LCD LED+ to 5V through a 220 ohm resistor

LCD LED- to GND
Additionally, wire a 10k potentiometer to +5V and GND, 
with it's wiper (output) to LCD screen's VO pin.
*/



//Include the LCD LIBRARY
#include <LiquidCrystal.h> 

/*
Make an object called "lcd" of class LiquidCrystal and set its parameters according to the following:
LiquidCrystal lcd(Register Select, Enable, D4, D5, D6, D7);
*/
LiquidCrystal lcd(2,3,4,5,6,7);

//Ultrasonic Sensor Setup pins and variables
const int trig=9; //Set trig pin on ultrasonic-sensor to pin 9.
const int echo=8; //Set echo pin on ultrasonic-sensor to pin 8.
float distance; //Initialize a global variable "distance"

//Set buzzer to pin 12.
const int buzzer=12;

void setup()
{
  /*
  Initialize the lcd object, the (16,2) refers to 
  the 16x2 LCD that we are using.
  Note: 
  16 is the number of columns available in the LCD. 
  2 is the number of rows available in the LCD.
  */
  lcd.begin(16,2); 
  pinMode(trig, OUTPUT);//Set trig pin to OUTPUT.
  pinMode(echo, INPUT);//Set echo pin to INPUT.
  pinMode(buzzer, OUTPUT);//Set buzzer pin to OUTPUT.
}

void loop()
{
  distance = get_distance(); //Get the distance
  lcd.clear();//Clear the LCD screen
  //Print the distance to the screen
  lcd.setCursor(0,0);//Set cursor on first column first row(starts at index 0)
  lcd.print("Distance:");
  lcd.setCursor(0,1);//Set cursor on first column second row
  lcd.print(String(distance)+"cm");
  //Check for any near obstacles 
  if(distance<=20){buzz(250);}
  else if(distance<=35){buzz(1000);}
  else if(distance<=50){buzz(2000);}
  delay(100);
}

/*
This function calculates the distance using the ultrasonic sensor.
We initialize this function as a float since it will return a float.
*/
float get_distance(){
  long duration; //initialize a local variable "duration".
  //Make sure that trigger is OFF for a short period.
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  //Set trigger to HIGH and send a 10 microsecond pulse.
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);//Turn trigger OFF.
  //Get the duration of echo being in a HIGH state in microseconds. 
  duration = pulseIn(echo,HIGH);
  /*
  Calculate the distance where 0.034cm/microseconds 
  -is the sound velocity, and return the answer.
  */
  return (duration*0.034)/2;
  
}

/*
This function will control the buzzer, 
it takes a parameter t which stands for time.
*/
void buzz(int t){
  digitalWrite(buzzer, HIGH);//Turn buzzer ON
  delay(t); //Wait for time t in milliseconds
  digitalWrite(buzzer, LOW); //Turn buzzer OFF
  delay(t);//Wait for time t in milliseconds
}