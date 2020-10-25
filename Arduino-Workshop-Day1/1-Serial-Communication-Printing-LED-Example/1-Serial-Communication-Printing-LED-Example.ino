/*
Serial Communication project (Printing to the screen):
This program functions the same as a blinking Led project, however 
-it prints the Led state and pin number to the screen.
 
 */
const int led=12; //Initialize led at digital pin number 12

void setup()
{
  pinMode(led, OUTPUT); //Set Led 13 to OUTPUT
  Serial.begin(9600); //Initialize Serial Communication at a baud rate of 9600
  digitalWrite(led,LOW);
}

void loop()
{
  digitalWrite(led, HIGH); //Set Led pin to HIGH
  //Remember to change led from int type to string type 
  Serial.println("The Led on pin number "+String(led)+" is ON!");  
  delay(1000); //Delay 1000 milliseconds
  digitalWrite(led, LOW);
  Serial.println("The Led on pin number "+String(led)+" is OFF!");
  delay(1000); 
}
