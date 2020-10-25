/*
For Loops with Leds:
1) Turn Led1 on and off 4 times with a delay of 1 second on each state. 
And print “Led1 is ON/OFF!” according to the state it is in.

2) Turn Led2 on and off 3 times with a delay of 0.5 seconds on each state. 
And print “Led2 is ON/OFF!” according to the state it is in.


*/

const int Led1=13; //Initialize Led1 at pin number 13
const int Led2=12; //Initialize Led2 at pin number 12

void setup()
{
  //Initialize all pins using a for-loop (DRY:Don't repeat yourself)
  for(int pin=12; pin<=13; pin++){
  	pinMode(pin, OUTPUT); //Set pin to OUTPUT
    digitalWrite(pin, LOW); //Set pin to LOW
  }
  Serial.begin(9600); //Initialize Serial Communication at a baud rate of 9600 
  
}

void loop()
{
  //Led1 Goes First
  for(int counter=0; counter<4; counter++){
  	digitalWrite(Led1, HIGH); //Set Led1 pin to HIGH 
  	Serial.println("Led1 is ON!");  
  	delay(1000); //Delay 1000 milliseconds 
  	digitalWrite(Led1, LOW); //Set Led1 pin to LOW
    Serial.println("Led1 is OFF!");
    delay(1000);
  }
  
  //Led2 Goes Second
  for(int counter=0; counter<3; counter++){
  	digitalWrite(Led2, HIGH); //Set Led2 pin to HIGH 
  	Serial.println("Led2 is ON!");  
  	delay(500); //Delay 500 milliseconds 
  	digitalWrite(Led2, LOW); //Set Led2 pin to LOW
    Serial.println("Led2 is OFF!");
    delay(500);
  }
   
}
