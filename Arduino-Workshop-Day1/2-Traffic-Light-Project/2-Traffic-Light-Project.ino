/*
Traffic Light Project:
1) Red is on for only 3 seconds. And print “Stop!”. 
2) Yellow is on for only 2 seconds. And print “Hurry UP!”. 
3) Green is on for only 2.5 seconds. And print “Go!”.
  
*/

const int RedLed=13; //Initialize Red led at pin number 13
const int YellowLed=12; //Initialize Yellow led at pin number 12
const int GreenLed=11; //Initialize Green led at pin number 11

void setup()
{
  //Initialize all pins using a for-loop (DRY:Don't repeat yourself)
  for(int pin=11; pin<=13; pin++){
  	pinMode(pin, OUTPUT); //Set pin to OUTPUT
    digitalWrite(pin, LOW); //Set pin to LOW
  }
  Serial.begin(9600); //Initialize Serial Communication at a baud rate of 9600 
  
}

void loop()
{
  //Red Light Goes First
  digitalWrite(RedLed, HIGH); //Set RedLed pin to HIGH 
  Serial.println("Stop!");  
  delay(3000); //Delay 3000 milliseconds 
  digitalWrite(RedLed, LOW); //Set RedLed pin to LOW
  
  //Yellow Light Goes Second
  digitalWrite(YellowLed, HIGH);  
  Serial.println("Hurry UP!");  
  delay(2000);
  digitalWrite(YellowLed, LOW); 
  
  //Green Light Goes Third
  digitalWrite(GreenLed, HIGH); 
  Serial.println("Go!");  
  delay(2500);  
  digitalWrite(GreenLed, LOW); 
   
}
