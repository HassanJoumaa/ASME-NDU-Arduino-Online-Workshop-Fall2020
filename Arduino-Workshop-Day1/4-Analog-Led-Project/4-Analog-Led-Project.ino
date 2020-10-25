/*
ANALOG LED PROJECT:
1) Use a for loop to gradually turn the LED ON. 
And then another for loop to gradually turn the LED OFF.
Hint: Use a delay of about 50 milliseconds and increment/decrement by 5 in each for-loop.
2) Print out the Analog value of pin 11. 
*/

const int PwmLed=11; //Initialize Led1 at pin number "~11". Pin 11 supports PWM!


void setup()
{
  pinMode(PwmLed, OUTPUT); //Set PwmLed to OUTPUT
  digitalWrite(PwmLed, LOW); //Set PwmLed to LOW
  Serial.begin(9600); //Initialize Serial Communication at a baud rate of 9600 
  
}

void loop()
{
  //Gradually turn PwmLed on from "0" (minimum value) to "255"(maximum value)
  for(int intensity=0; intensity<=255; intensity+=5){
  	analogWrite(PwmLed, intensity); //Set Analog value for PwmLed
  	Serial.println("PWMLed intensity is: "+ String(analogRead(PwmLed)));  
  	delay(50); //Delay 50 milliseconds 
  }
  
  //Gradually turn PwmLed off from "255"(maximum value)to "0" (minimum value)
  for(int intensity=255; intensity>=0; intensity-=5){
  	analogWrite(PwmLed, intensity); //Set Analog value for PwmLed 
  	Serial.println("PWMLed intensity is: "+ String(analogRead(PwmLed)));  
  	delay(50); //Delay 50 milliseconds 
  }
   
}
